#include <iostream>
#include <fstream>  
#include <string>  
using namespace std;                                                            
                    
void He3_QF(){

  //string  pname="../BackUP/he3.dat";
  string  pname="param/3he_remake.dat";
  ifstream ifp(pname.c_str());

  double mom[2000],ratio[2000];
  double order[2000];
  string buf;
  string mom_st,ratio_st;
  string order_st;
  int i=0;

  TGraphErrors* gQF=new TGraphErrors();
  gQF->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF->SetMarkerColor(2);
  while( ifp.eof()==0){
    order[i]=0.0;
    mom[i]=0.0;
    ratio[i]=0.0;

    getline(ifp,buf);
    if(buf.length()<5)break;
    mom_st=buf.substr(3,16);
    ratio_st=buf.substr(26,17);
    order_st=buf.substr(44,3);
    if(buf.length()>=48) order_st="000";

    mom[i]   = stod(mom_st);
    ratio[i] = stod(ratio_st);
    order[i] = stod(order_st);
    //    cout<<"mom_st "<<mom_st<<" ratio_st "<<ratio_st<<" order_st "<<order_st<<endl;
    if(order[i]==0)order[i]=1.0;
    else order[i] = pow(10.,order[i]);
    
    ratio[i]= ratio[i] * order[i];

    if(i==0)gQF->SetPoint(i,mom[i],ratio[i]);
    else gQF->SetPoint(i,mom[i],ratio[i]-ratio[i-1]);

    //    cout<<"mom "<<mom[i]<<" ratio "<<ratio[i]<<" order "<<order[i]<<endl;
    i++;

  }



  
  TCanvas* c0 =new TCanvas("c0","c0");
  c0->cd();
  gQF->Draw("AP");

}
