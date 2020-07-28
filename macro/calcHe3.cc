

void calcHe3(){

  string  pname="param/3he_ita.dat";
  ifstream ifp(pname.c_str());
  string opname="param/he3_theory.dat";
  ofstream ofp(opname.c_str());
  double mom[2000],ratio[2000];
  double err[2000];
  string buf;
  string mom_st,ratio_st;
  string err_st;
  int i=0;
  double Ans=0;
  double ans;
  TGraphErrors* gQF=new TGraphErrors();
  gQF->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF->SetMarkerColor(2);
  gQF->SetMarkerStyle(20);
  while( ifp.eof()==0){
    err[i]=0.0;
    mom[i]=0.0;
    ratio[i]=0.0;




    getline(ifp,buf);
    if(buf.length()<5)break;
    //    cout<<"buf "<<buf<<endl;
    ans=0.0;
    mom_st=buf.substr(2,3);
    ratio_st=buf.substr(7,12);
    err_st=buf.substr(21,10);


    mom[i]   = stod(mom_st)*200.;
    ratio[i] = stod(ratio_st);
    err[i] = stod(err_st);
    if(i!=0)ans=4*3.14/pow(3.14*2.0,3)*ratio[i]*(mom[i]-mom[i-1])*mom[i]*mom[i]/pow(200.,3.);
    Ans+=ans/1.354;
    gQF->SetPoint(i,mom[i],ans);
    ofp << mom[i] <<" "<<Ans<<endl;

    i++;

  }
  TCanvas* c0 =new TCanvas("c0","c0");
  c0->cd();
  gQF->Draw("AP");



}
