

void calc2H(){

  string  pname="param/2H_AV18.dat";
  ifstream ifp(pname.c_str());
  string opname1="param/2h_AV18_KS.dat";
  string opname2="param/2h_AV18_DS.dat";
  string opname3="param/2h_AV18_K.dat";
  
  ofstream ofp1(opname1.c_str());
  ofstream ofp2(opname2.c_str());
  ofstream ofp3(opname3.c_str());
  
  double mom[2000],rhoKS[2000],rhoDS[2000],rhoK[2000],rho[2000];
  double err[2000];
  string buf;
  string mom_st,KS_st,DS_st,K_st;
  int i=0;
  double Ans1,Ans2,Ans3;
  double ans1,ans2,ans3;
  Ans1 =0.0;
  Ans2 =0.0;
  Ans3 =0.0;
  
  double norm1,norm2,norm3;
  norm1 =  0.94238;
  norm2 =  0.057599;
  norm3 =  0.99998;
  double hbarc = 197.32705;
  

  TGraphErrors* gF1=new TGraphErrors();
  TGraphErrors* gF2=new TGraphErrors();
  TGraphErrors* gF3=new TGraphErrors();
  //  gF1->SetTitle("3H Fermi mom distribution ; p_{M} [MeV/c]; probability");
  //  double norm1 = 2.002;
  //  double norm2 = 0.0;
  //  double norm3 =0.0;
  gF1->SetName("gF1");
  gF1->SetMarkerColor(4);
  gF1->SetMarkerStyle(31);
  gF2->SetName("gF2");
  gF2->SetMarkerColor(2);
  gF2->SetMarkerStyle(31);
  gF3->SetName("gF3");
  gF3->SetTitle("Dueteron Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gF3->SetMarkerColor(3);
  gF3->SetMarkerStyle(31);
  
  while( ifp.eof()==0){

    mom[i]   = 0.0;
    rhoKS[i] = 0.0;
    rhoDS[i] = 0.0;
    rhoK[i]  = 0.0;
    rho[i]   = 0.0;

    getline(ifp,buf);
    if(buf.length()<5)break;

    ans1=0.0;
    ans2=0.0;
    ans3=0.0;
    mom_st = buf.substr(0,5);
    KS_st  = buf.substr(7,13);
    DS_st  = buf.substr(22,10);
    K_st   = buf.substr(34,13);
    mom[i]   = stod(mom_st)* hbarc;

    rhoKS[i] = stod(KS_st,nullptr);
    rhoDS[i] = stod(DS_st,nullptr);
    rhoK[i]  = stod(K_st,nullptr);

    rhoKS[i] /= norm1;
    rhoDS[i] /= norm2;
    rhoK[i]  /= norm3;
    
    if(i!=0){
      ans1=4*3.14/pow(3.14*2.0,3)*rhoKS[i]*(mom[i]-mom[i-1])*mom[i]*mom[i]/pow(hbarc,3.);
      ans2=4*3.14/pow(3.14*2.0,3)*rhoDS[i]*(mom[i]-mom[i-1])*mom[i]*mom[i]/pow(hbarc,3.);
      ans3=4*3.14/pow(3.14*2.0,3)*rhoK[i]*(mom[i]-mom[i-1])*mom[i]*mom[i]/pow(hbarc,3.);
    }else{
      ans1=4*3.14/pow(3.14*2.0,3)*rhoKS[i]*(mom[i])*mom[i]*mom[i]/pow(hbarc,3.);
      ans2=4*3.14/pow(3.14*2.0,3)*rhoDS[i]*(mom[i])*mom[i]*mom[i]/pow(hbarc,3.);
      ans3=4*3.14/pow(3.14*2.0,3)*rhoK[i]*(mom[i])*mom[i]*mom[i]/pow(hbarc,3.);
    }


   
    
    Ans1 += ans1;
    Ans2 += ans2;
    Ans3 += ans3;
    
      ofp1 << mom[i] <<" "<<ans1<<" "<<Ans1<<endl;
      gF1->SetPoint(i,mom[i],ans1);
      ofp2 << mom[i] <<" "<<ans2<<" "<<Ans2<<endl;
      gF2->SetPoint(i,mom[i],ans2);
      ofp3 << mom[i] <<" "<<ans3<<" "<<Ans3<<endl;
      gF3->SetPoint(i,mom[i],ans3);


    
    
    i++;

  }
  TCanvas* c0 =new TCanvas("c0","c0");
  c0->cd();
  gF3->Draw("APL");
  gF1->Draw("PL");
  gF2->Draw("PL");



}
