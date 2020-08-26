

void benharsf2(){

  string param="./benharsf_3mod.dat";
  ifstream ifp(param.c_str(),ios::in);
  string buf;
  int ii=0;
  double hbarc =197.;// MeV *fm
  double pfer[2000],k[2000],Em[2000],SFn[2000],SFp[2000],dpfer[2000],dEm[2000];
  getline(ifp,buf);
  stringstream sbuf(buf);
  int npfer,nEm;
  sbuf >> npfer >> nEm;
  cout<<"npfer "<<npfer<<" nEm "<<nEm<<endl;
  
  while(!ifp.eof()){
    getline(ifp,buf);
    stringstream sbuf(buf);
    sbuf >> pfer[ii] >> Em[ii] >> SFp[ii] >> SFn[ii] >> dpfer[ii] >> dEm[ii];
    k[ii] = pfer[ii]/hbarc;
    ii++;
  }


  //  TH2D* hSFp =new TH2D("hSFp","SF proton; k [1/fm] ; Em [MeV]",npfer,0,5.,nEm,0,250);
  //    TH2D* hSFn =new TH2D("hSFn","SF nuetron; k [1/fm] ; Em [MeV]",npfer,0,5.,nEm,0,250);  
  TH2D* hSFp =new TH2D("hSFp","SF proton; Em [MeV]; k [1/fm] ; k^2P(k,E)",nEm+1,0,200,npfer+1,0,5.);
  TH2D* hSFn =new TH2D("hSFn","SF nuetron; Em [MeV] ; k [1/fm] ; k^2P(k,E)",nEm+1,0,200,npfer+1,0,5.);  

  int n=0;
  int n0;
  for(int ip=0;ip<npfer;ip++){
    for(int iEm=0;iEm<nEm;iEm++){
      //            if(iEm==0)cout<<"Em "<<Em[n]<<" k "<<k[n]<<" SFp "<<SFp[n]*k[n]*k[n]<<" SFn "<<SFn[n]*k[n]*k[n]<<endl;
      //      hSFp->Fill(Em[n],k[n], SFp[n]*k[n]*k[n]);
      //      hSFn->Fill(Em[n],k[n], SFn[n]*k[n]*k[n]);
      if(iEm==0)n0 = n;
      hSFp->Fill(Em[n],k[n], SFp[n0]*k[n]*k[n]);
      hSFn->Fill(Em[n],k[n], SFn[n0]*k[n]*k[n]);
      
      n++;
    }
  }

  TCanvas* c0 =new TCanvas("c0","c0");
  //  c0->Divide(2,1);
  c0->cd(1);
  gPad->SetLogz(1);
  hSFp->GetYaxis()->SetNdivisions(505);
  hSFp->GetXaxis()->SetTitleOffset(1.5);
  hSFp->GetYaxis()->SetTitleOffset(2.0);
  hSFp->GetZaxis()->SetTitleOffset(2.0);
  hSFp->GetYaxis()->SetRangeUser(0,4);
  //  hSFp->GetYaxis()->SetRangeUser(50,250);
  hSFp->GetXaxis()->SetRangeUser(0,100);
  hSFp->GetZaxis()->SetRangeUser(10e-5,5e-2);  
  hSFp->Draw("LEGO2");
  TCanvas* c1 =new TCanvas("c1","c1");
  //  c0->Divide(2,1);
  c1->cd(1);

  gPad->SetLogz(1);
  hSFn->GetYaxis()->SetNdivisions(505);
  hSFn->GetXaxis()->SetTitleOffset(1.5);
  hSFn->GetYaxis()->SetTitleOffset(2.0);
  hSFn->GetZaxis()->SetTitleOffset(2.0);
  hSFn->GetYaxis()->SetRangeUser(0,4);
  //hSFn->GetYaxis()->SetRangeUser(50,250);
  hSFn->GetXaxis()->SetRangeUser(0,100);
  hSFn->GetZaxis()->SetRangeUser(10e-5,5e-2);  
  hSFn->Draw("LEGO2");  
  //  TCanvas* c0 =new TCanvas("c0","c0");
  //  c0->cd();
  //  hSFp->Draw("LEGO2");
  
}
