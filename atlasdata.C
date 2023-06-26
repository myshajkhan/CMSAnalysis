#include "Riostream.h" //automatically provides std;;
#include <iostream>
#include <fstream>
#include "TH1F.h"
#include <TMath.h>
#include "TCanvas.h"
#include "TLegend.h"

void atlasdata(){
ifstream in; //ifstream is an input stream class in C++ that is used for reading data from files.
in.open(Form("ATLAS_higgs_test.dat")); //you are opening out.dat file 

//declaration of an object named ntuple -provides a way to store and organize data
TNtuple ntuple("ntuple", "data from ascii file", "Z1mass:Z2mass:mass4l:detajj:massjj:l1pdgid:l1pt:l1eta:l1phi:l2pdgid:l2pt:l2eta:l2phi:l3pdgid:l3pt:l3eta:l3phi:l4pdgid:l4pt:l4eta:l4phi:j1pt:j1eta:j1phi:j1E:j2pt:j2eta:j2phi:j2E:source");

Int_t nlines = 0; //variable is used to keep track of the number of lines read from the input file.
//declaring histograms for signal
auto f = TFile::Open("ATLAS_higgs_test.root","RECREATE");
TH1F sZ1mass("sZ1mass", "Z1mass distribution", 100, 0, 500);
TH1F sZ2mass("sZ2mass", "Z2mass distribution", 100, 0, 500);
TH1F smass4l("smass4l", "mass4l distribution", 100, 0, 300);
TH1F sdetajj("sdetajj", "detajj distribution", 100, 0, 10);
TH1F smassjj("smassjj", "massjj distribution", 100, 0, 500);
TH1I sl1pdgid("sl1pdgid", "l1pdgid distribution", 100, -50, 50);
TH1F sl1pt("sl1pt", "l1pt distribution", 100, 0, 500);
TH1F sl1eta("sl1eta", "l1eta distribution", 100, -5, 5);
TH1F sl1phi("sl1phi", "l1phi distribution", 100, -4, 4);
TH1I sl2pdgid("sl2pdgid", "l2pdgid distribution", 100, -15, 15);
TH1F sl2pt("sl2pt", "l2pt distribution", 100, 0, 300);
TH1F sl2eta("sl2eta", "l2eta distribution", 100, -5, 5);
TH1F sl2phi("sl2phi", "l2phi distribution", 100, -5, 5);
TH1I sl3pdgid("sl3pdgid", "l3pdgid distribution", 100, -15, 15);
TH1F sl3pt("sl3pt", "l3pt distribution", 100, 0, 300);
TH1F sl3eta("sl3eta", "l3eta distribution", 100, -5, 5);
TH1F sl3phi("sl3phi", "l3phi distribution", 100, -5, 5);
TH1I sl4pdgid("sl4pdgid", "l4pdgid distribution", 100, -15, 15);
TH1F sl4pt("sl4pt", "l4pt distribution", 100, 0, 100);
TH1F sl4eta("sl4eta", "l4eta distribution", 100, -5, 5);
TH1F sl4phi("sl4phi", "l4phi distribution", 100, -5, 5);
TH1F sj1pt("sj1pt", "j1pt distribution", 100, 0, 1000);
TH1F sj1eta("sj1eta", "j1eta distribution", 100, -5, 5);
TH1F sj1phi("sj1phi", "j1phi distribution", 100, -5, 5);
TH1F sj1E("sj1E", "j1E distribution", 100, 0, 3000);
TH1F sj2pt("sj2pt", "j2pt distribution", 100, 0, 500);
TH1F sj2eta("sj2eta", "j2eta distribution", 100, -5, 5);
TH1F sj2phi("sj2phi", "j2phi distribution", 100, -5, 5);
TH1F sj2E("sj2E", "j2E distribution", 100, 0, 2000);
//TH1I source("hsource", "source distribution", 10, 0, 10);
//declaring hists for background 

TH1F bZ1mass("bZ1mass", "Z1mass distribution", 100, 0, 500);
TH1F bZ2mass("bZ2mass", "Z2mass distribution", 100, 0, 500);
TH1F bmass4l("bmass4l", "mass4l distribution", 100, 0, 300);
TH1F bdetajj("bdetajj", "detajj distribution", 100, 0, 10);
TH1F bmassjj("bmassjj", "massjj distribution", 100, 0, 500);
TH1I bl1pdgid("bl1pdgid", "l1pdgid distribution", 100, -50, 50);
TH1F bl1pt("bl1pt", "l1pt distribution", 100, 0, 500);
TH1F bl1eta("bl1eta", "l1eta distribution", 100, -5, 5);
TH1F bl1phi("bl1phi", "l1phi distribution", 100, -5, 5);
TH1I bl2pdgid("bl2pdgid", "l2pdgid distribution", 100, -15, 15);
TH1F bl2pt("bl2pt", "l2pt distribution", 100, 0, 300);
TH1F bl2eta("bl2eta", "l2eta distribution", 100, -5, 5);
TH1F bl2phi("bl2phi", "l2phi distribution", 100, -5, 5);
TH1I bl3pdgid("bl3pdgid", "l3pdgid distribution", 100, -15, 15);
TH1F bl3pt("bl3pt", "l3pt distribution", 100, 0, 300);
TH1F bl3eta("bl3eta", "l3eta distribution", 100, -5, 5);
TH1F bl3phi("bl3phi", "l3phi distribution", 100, -5, 5);
TH1I bl4pdgid("bl4pdgid", "l4pdgid distribution", 100, -15, 15);
TH1F bl4pt("bl4pt", "l4pt distribution", 100, 0, 100);
TH1F bl4eta("bl4eta", "l4eta distribution", 100, -5, 5);
TH1F bl4phi("bl4phi", "l4phi distribution", 100, -5, 5);
TH1F bj1pt("bj1pt", "j1pt distribution", 100, 0, 1000);
TH1F bj1eta("bj1eta", "j1eta distribution", 100, -5, 5);
TH1F bj1phi("bj1phi", "j1phi distribution", 100, -5, 5);
TH1F bj1E("bj1E", "j1E distribution", 100, 0, 3000);
TH1F bj2pt("bj2pt", "j2pt distribution", 100, 0, 500);
TH1F bj2eta("bj2eta", "j2eta distribution", 100, -5, 5);
TH1F bj2phi("bj2phi", "j2phi distribution", 100, -5, 5);
TH1F bj2E("bj2E", "j2E distribution", 100, 0, 2000);


 // Create variables to hold the data
    double Z1mass, Z2mass, mass4l, detajj, massjj;
    int l1pdgid, l2pdgid, l3pdgid, l4pdgid;
    double l1pt, l1eta, l1phi, l2pt, l2eta, l2phi, l3pt, l3eta, l3phi, l4pt, l4eta, l4phi;
    double j1pt, j1eta, j1phi, j1E, j2pt, j2eta, j2phi, j2E;
    int  source ;


// create a TTree and it's braches so we can separate signal and background
   TTree *signal = new TTree("signal","signal or background");
  TTree *background = new TTree("background","signal or background");
while (1){
    in >> Z1mass >> Z2mass >> mass4l >> detajj >> massjj >> l1pdgid >> l1pt >> l1eta >> l1phi >> l2pdgid >> l2pt >> l2eta >> l2phi >> l3pdgid >> l3pt >> l3eta >> l3phi >> l4pdgid >> l4pt >> l4eta >> l4phi >> j1pt >> j1eta >> j1phi >> j1E >> j2pt >> j2eta >> j2phi >> j2E >> source;
    if (!in.good()) break;
  //  if (nlines < 10000) printf("Z1mass=%8f, Z2mass=%8f, mass4l=%8f, detajj=%8f, massjj=%8f, l1pdgid=%d, l1pt=%8f, l1eta=%8f, l1phi=%8f\n", Z1mass, Z2mass, mass4l, detajj, massjj, l1pdgid, l1pt, l1eta, l1phi);
        if (source== 1){   //when signal 
    signal->Branch("Z1mass", &Z1mass);
    signal->Branch("Z2mass", &Z2mass);
    signal->Branch("mass4l", &mass4l);
    signal->Branch("detajj", &detajj);
    signal->Branch("massjj", &massjj);
    signal->Branch("l1pdgid", &l1pdgid);
    signal->Branch("l1pt", &l1pt);
    signal->Branch("l1eta", &l1eta);
    signal->Branch("l1phi", &l1phi);
    signal->Branch("l2pdgid", &l2pdgid);
    signal->Branch("l2pt", &l2pt);
    signal->Branch("l2eta", &l2eta);
    signal->Branch("l2phi", &l2phi);
    signal->Branch("l3pdgid", &l3pdgid);
    signal->Branch("l3pt", &l3pt);
    signal->Branch("l3eta", &l3eta);
    signal->Branch("l3phi", &l3phi);
    signal->Branch("l4pdgid", &l4pdgid);
    signal->Branch("l4pt", &l4pt);
    signal->Branch("l4eta", &l4eta);
    signal->Branch("l4phi", &l4phi);
    signal->Branch("j1pt", &j1pt);
    signal->Branch("j1eta", &j1eta);
    signal->Branch("j1phi", &j1phi);
    signal->Branch("j1E", &j1E);
    signal->Branch("j2pt", &j2pt);
    signal->Branch("j2eta", &j2eta);
    signal->Branch("j2phi", &j2phi);
    signal->Branch("j2E", &j2E);



        
    sZ1mass.Fill(Z1mass);
    sZ2mass.Fill(Z2mass);
    smass4l.Fill(mass4l);
    sdetajj.Fill(detajj);
    smassjj.Fill(massjj);
    sl1pdgid.Fill(l1pdgid);
    sl1pt.Fill(l1pt);
    sl1eta.Fill(l1eta);
    sl1phi.Fill(l1phi);
    sl2pdgid.Fill(l2pdgid);
    sl2pt.Fill(l2pt);
    sl2eta.Fill(l2eta);
    sl2phi.Fill(l2phi);
    sl3pdgid.Fill(l3pdgid);
    sl3pt.Fill(l3pt);
    sl3eta.Fill(l3eta);
    sl3phi.Fill(l3phi);
    sl4pdgid.Fill(l4pdgid);
    sl4pt.Fill(l4pt);
    sl4eta.Fill(l4eta);
    sl4phi.Fill(l4phi);
    sj1pt.Fill(j1pt);
    sj1eta.Fill(j1eta);
    sj1phi.Fill(j1phi);
    sj1E.Fill(j1E);
    sj2pt.Fill(j2pt);
    sj2eta.Fill(j2eta);
    sj2phi.Fill(j2phi);
    sj2E.Fill(j2E);
  



} else {

    background->Branch("Z1mass", &Z1mass);
    background->Branch("Z2mass", &Z2mass);
    background->Branch("mass4l", &mass4l);
    background->Branch("detajj", &detajj);
    background->Branch("massjj", &massjj);
    background->Branch("l1pdgid", &l1pdgid);
    background->Branch("l1pt", &l1pt);
    background->Branch("l1eta", &l1eta);
    background->Branch("l1phi", &l1phi);
    background->Branch("l2pdgid", &l2pdgid);
    background->Branch("l2pt", &l2pt);
    background->Branch("l2eta", &l2eta);
    background->Branch("l2phi", &l2phi);
    background->Branch("l3pdgid", &l3pdgid);
    background->Branch("l3pt", &l3pt); 
    background->Branch("l3eta", &l3eta);
    background->Branch("l3phi", &l3phi);
    background->Branch("l4pdgid", &l4pdgid);
    background->Branch("l4pt", &l4pt);
    background->Branch("l4eta", &l4eta);
    background->Branch("l4phi", &l4phi);
    background->Branch("j1pt", &j1pt);
    background->Branch("j1eta", &j1eta);
    background->Branch("j1phi", &j1phi);
    background->Branch("j1E", &j1E);
    background->Branch("j2pt", &j2pt);
    background->Branch("j2eta", &j2eta);
    background->Branch("j2phi", &j2phi);
    background->Branch("j2E", &j2E);
  
  //filling the histogram for background

    bZ1mass.Fill(Z1mass);
    bZ2mass.Fill(Z2mass);
    bmass4l.Fill(mass4l);
    bdetajj.Fill(detajj);
    bmassjj.Fill(massjj);
    bl1pdgid.Fill(l1pdgid);
    bl1pt.Fill(l1pt);
    bl1eta.Fill(l1eta);
    bl1phi.Fill(l1phi);
    bl2pdgid.Fill(l2pdgid);
    bl2pt.Fill(l2pt);
    bl2eta.Fill(l2eta);
    bl2phi.Fill(l2phi);
    bl3pdgid.Fill(l3pdgid);
    bl3pt.Fill(l3pt);
    bl3eta.Fill(l3eta);
    bl3phi.Fill(l3phi);
    bl4pdgid.Fill(l4pdgid);
    bl4pt.Fill(l4pt);
    bl4eta.Fill(l4eta);
    bl4phi.Fill(l4phi);
    bj1pt.Fill(j1pt);
    bj1eta.Fill(j1eta);
    bj1phi.Fill(j1phi);
    bj1E.Fill(j1E);
    bj2pt.Fill(j2pt);
    bj2eta.Fill(j2eta);
    bj2phi.Fill(j2phi);
    bj2E.Fill(j2E);
  

}
    nlines++;
}

std::vector<TCanvas*> canvases;
//Drawing histograms
// Create the first canvas
gStyle->SetOptStat();

THStack hs1("hs1","Z1mass");
TCanvas *c1 = new TCanvas("c1", "c1", 800, 800);
c1->Divide(2, 2);

//LEGEND ENTRY
TLegend *legend1 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend1->AddEntry(&sZ1mass, "Signal", "l");
legend1->AddEntry(&sZ1mass, Form("Entries %.2f", sZ1mass.GetEntries()));
legend1->AddEntry(&sZ1mass, Form("Mean %.2f", sZ1mass.GetMean()));
legend1->AddEntry(&sZ1mass, Form("Stdev %.2f", sZ1mass.GetRMS()));
legend1->AddEntry(&bZ1mass, "Background", "l");
legend1->AddEntry(&bZ1mass, Form("Entries %.2f", sZ1mass.GetEntries()));
legend1->AddEntry(&bZ1mass, Form("Mean %.2f", bZ1mass.GetMean()));
legend1->AddEntry(&bZ1mass, Form("Stdev %.2f", bZ1mass.GetRMS()));
legend1->SetFillColor(kWhite);

c1->cd(1);
sZ1mass.SetLineColor(kBlue);
bZ1mass.SetLineColor(kRed);
hs1.Add(&sZ1mass);
hs1.Add(&bZ1mass);
hs1.Draw("nostack");
legend1->Draw();


TLegend *legend2 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend2->AddEntry(&sZ2mass, "Signal", "l");
legend2->AddEntry(&sZ2mass, Form("Entries %.2f", sZ2mass.GetEntries()));
legend2->AddEntry(&sZ2mass, Form("Mean %.2f", sZ2mass.GetMean()));
legend2->AddEntry(&sZ2mass, Form("Stdev %.2f", sZ2mass.GetRMS()));
legend2->AddEntry(&bZ2mass, "Background", "l");
legend2->AddEntry(&bZ2mass, Form("Entries %.2f", sZ2mass.GetEntries()));
legend2->AddEntry(&bZ2mass, Form("Mean %.2f", bZ2mass.GetMean()));
legend2->AddEntry(&bZ2mass, Form("Stdev %.2f", bZ2mass.GetRMS()));
legend2->SetFillColor(kWhite);


THStack hs2("hs2","Z2mass");
c1->cd(2);
sZ2mass.SetLineColor(kBlue);
bZ2mass.SetLineColor(kRed);
hs2.Add(&sZ2mass);
hs2.Add(&bZ2mass);
hs2.Draw("nostack");
legend2->Draw();



TLegend *legend3 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend3->AddEntry(&smass4l, "signal", "l");
legend3->AddEntry(&smass4l, Form("Entries %.2f", smass4l.GetEntries()));
legend3->AddEntry(&smass4l, Form("Mean %.2f", smass4l.GetMean()));
legend3->AddEntry(&smass4l, Form("Stdev %.2f", smass4l.GetRMS()));
legend3->AddEntry(&bmass4l, "Background", "l");
legend3->AddEntry(&bmass4l, Form("Entries %.2f", smass4l.GetEntries()));
legend3->AddEntry(&bmass4l, Form("Mean %.2f", bmass4l.GetMean()));
legend3->AddEntry(&bmass4l, Form("Stdev %.2f", bmass4l.GetRMS()));
legend3->SetFillColor(kWhite);

THStack hs3("hs3","mass4l");
c1->cd(3);
smass4l.SetLineColor(kBlue);
bmass4l.SetLineColor(kRed);
hs3.Add(&smass4l);
hs3.Add(&bmass4l);
hs3.Draw("nostack");
legend3->Draw();




TLegend *legend4 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend4->AddEntry(&sdetajj, "signal", "l");
legend4->AddEntry(&sdetajj, Form("Entries %.2f", sdetajj.GetEntries()));
legend4->AddEntry(&sdetajj, Form("Mean %.2f", sdetajj.GetMean()));
legend4->AddEntry(&sdetajj, Form("Stdev %.2f", sdetajj.GetRMS()));
legend4->AddEntry(&bdetajj, "Background", "l");
legend4->AddEntry(&bdetajj, Form("Entries %.2f", bdetajj.GetEntries()));
legend4->AddEntry(&bdetajj, Form("Mean %.2f", bdetajj.GetMean()));
legend4->AddEntry(&bdetajj, Form("Stdev %.2f", bdetajj.GetRMS()));
legend4->SetFillColor(kWhite);
THStack hs4("hs4","detajj");
c1->cd(4);
sdetajj.SetLineColor(kBlue);
bdetajj.SetLineColor(kRed);
hs4.Add(&sdetajj);
hs4.Add(&bdetajj);
hs4.Draw("nostack");
legend4->Draw();

c1->Update();
canvases.push_back(c1);
 
// Create the second canvas
THStack hs5("hs5","massjj");
TCanvas *c2 = new TCanvas("c2", "c2", 800, 800);
c2->Divide(2, 2);


TLegend *legend5 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend5->AddEntry(&smassjj, "Signal", "l");
legend5->AddEntry(&smassjj, Form("Entries %.2f", smassjj.GetEntries()));
legend5->AddEntry(&smassjj, Form("Mean %.2f", smassjj.GetMean()));
legend5->AddEntry(&smassjj, Form("Stdev %.2f", smassjj.GetRMS()));
legend5->AddEntry(&bmassjj, "Background", "l");
legend5->AddEntry(&bmassjj, Form("Entries %.2f", bmassjj.GetEntries()));
legend5->AddEntry(&bmassjj, Form("Mean %.2f", bmassjj.GetMean()));
legend5->AddEntry(&bmassjj, Form("Stdev %.2f", bmassjj.GetRMS()));
legend5->SetFillColor(kWhite);
c2->cd(1);
smassjj.SetLineColor(kBlue);
bmassjj.SetLineColor(kRed);
hs5.Add(&smassjj);
hs5.Add(&bmassjj);
hs5.Draw("nostack");
legend5->Draw();


TLegend *legend6 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend6->AddEntry(&sl1pdgid, "Signal", "l");
legend6->AddEntry(&sl1pdgid, Form("Entries %.2f", sl1pdgid.GetEntries()));
legend6->AddEntry(&sl1pdgid, Form("Mean %.2f", sl1pdgid.GetMean()));
legend6->AddEntry(&sl1pdgid, Form("Stdev %.2f", sl1pdgid.GetRMS()));
legend6->AddEntry(&bl1pdgid, "Background", "l");
legend6->AddEntry(&bl1pdgid, Form("Entries %.2f", bl1pdgid.GetEntries()));
legend6->AddEntry(&bl1pdgid, Form("Mean %.2f", bl1pdgid.GetMean()));
legend6->AddEntry(&bl1pdgid, Form("Stdev %.2f", bl1pdgid.GetRMS()));
legend6->SetFillColor(kWhite);
THStack hs6("hs6","l1pdgid");
c2->cd(2);
sl1pdgid.SetLineColor(kBlue);
bl1pdgid.SetLineColor(kRed);
hs6.Add(&sl1pdgid);
hs6.Add(&bl1pdgid);
hs6.Draw("nostack");
legend6->Draw();



TLegend *legend7 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend7->AddEntry(&sl1pt, "Signal", "l");
legend7->AddEntry(&sl1pt, Form("Entries %.2f", sl1pt.GetEntries()));
legend7->AddEntry(&sl1pt, Form("Mean %.2f", sl1pt.GetMean()));
legend7->AddEntry(&sl1pt, Form("Stdev %.2f", sl1pt.GetRMS()));
legend7->AddEntry(&bl1pt, "Background", "l");
legend7->AddEntry(&bl1pt, Form("Entries %.2f", bl1pt.GetEntries()));
legend7->AddEntry(&bl1pt, Form("Mean %.2f", bl1pt.GetMean()));
legend7->AddEntry(&bl1pt, Form("Stdev %.2f", bl1pt.GetRMS()));
legend7->SetFillColor(kWhite);

THStack hs7("hs7","l1pt");
c2->cd(3);
sl1pt.SetLineColor(kBlue);
bl1pt.SetLineColor(kRed);
hs7.Add(&sl1pt);
hs7.Add(&bl1pt);
hs7.Draw("nostack");
legend7->Draw();


TLegend *legend8 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend8->AddEntry(&sl1eta, "Signal", "l");
legend8->AddEntry(&sl1eta, Form("Entries %.2f", sl1eta.GetEntries()));
legend8->AddEntry(&sl1eta, Form("Mean %.2f", sl1eta.GetMean()));
legend8->AddEntry(&sl1eta, Form("Stdev %.2f", sl1eta.GetRMS()));
legend8->AddEntry(&bl1eta, "Background", "l");
legend8->AddEntry(&bl1eta, Form("Entries %.2f", bl1eta.GetEntries()));
legend8->AddEntry(&bl1eta, Form("Mean %.2f", bl1eta.GetMean()));
legend8->AddEntry(&bl1eta, Form("Stdev %.2f", bl1eta.GetRMS()));
legend8->SetFillColor(kWhite);
THStack hs8("hs8","l1eta");
c2->cd(4);
sl1eta.SetLineColor(kBlue);
bl1eta.SetLineColor(kRed);
hs8.Add(&sl1eta);
hs8.Add(&bl1eta);
hs8.Draw("nostack");
legend8->Draw();


c2->Update();
canvases.push_back(c2);

// Create the third canvas

TCanvas *c3 = new TCanvas("c3", "c3", 800, 800);
c3->Divide(2, 2);

TLegend *legend9 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend9->AddEntry(&sl1phi, "Signal", "l");
legend9->AddEntry(&sl1phi, Form("Entries %.2f", sl1phi.GetEntries()));
legend9->AddEntry(&sl1phi, Form("Mean %.2f", sl1phi.GetMean()));
legend9->AddEntry(&sl1phi, Form("Stdev %.2f", sl1phi.GetRMS()));
legend9->AddEntry(&bl1phi, "Background", "l");
legend9->AddEntry(&bl1phi, Form("Entries %.2f", bl1phi.GetEntries()));
legend9->AddEntry(&bl1phi, Form("Mean %.2f", bl1phi.GetMean()));
legend9->AddEntry(&bl1phi, Form("Stdev %.2f", bl1phi.GetRMS()));
legend9->SetFillColor(kWhite);

THStack hs9("hs9","l1phi");
c3->cd(1);
sl1phi.SetLineColor(kBlue);
bl1phi.SetLineColor(kRed);
hs9.Add(&sl1phi);
hs9.Add(&bl1phi);
hs9.Draw("nostack");
legend9->Draw();





TLegend *legend10 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend10->AddEntry(&sl2pdgid, "Signal", "l");
legend10->AddEntry(&sl2pdgid, Form("Entries %.2f", sl2pdgid.GetEntries()));
legend10->AddEntry(&sl2pdgid, Form("Mean %.2f", sl2pdgid.GetMean()));
legend10->AddEntry(&sl2pdgid, Form("Stdev %.2f", sl2pdgid.GetRMS()));
legend10->AddEntry(&bl2pdgid, "Background", "l");
legend10->AddEntry(&bl2pdgid, Form("Entries %.2f", bl2pdgid.GetEntries()));
legend10->AddEntry(&bl2pdgid, Form("Mean %.2f", bl2pdgid.GetMean()));
legend10->AddEntry(&bl2pdgid, Form("Stdev %.2f", bl2pdgid.GetRMS()));
legend10->SetFillColor(kWhite);

THStack hs10("hs10","l2pdgid");
c3->cd(2);
sl2pdgid.SetLineColor(kBlue);
bl2pdgid.SetLineColor(kRed);
hs10.Add(&sl2pdgid);
hs10.Add(&bl2pdgid);
hs10.Draw("nostack");
legend10->Draw();


TLegend *legend11 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend11->AddEntry(&sl2pt, "Signal", "l");
legend11->AddEntry(&sl2pt, Form("Entries %.2f", sl2pt.GetEntries()));
legend11->AddEntry(&sl2pt, Form("Mean %.2f", sl2pt.GetMean()));
legend11->AddEntry(&sl2pt, Form("Stdev %.2f", sl2pt.GetRMS()));
legend11->AddEntry(&bl2pt, "Background", "l");
legend11->AddEntry(&bl2pt, Form("Entries %.2f", bl2pt.GetEntries()));
legend11->AddEntry(&bl2pt, Form("Mean %.2f", bl2pt.GetMean()));
legend11->AddEntry(&bl2pt, Form("Stdev %.2f", bl2pt.GetRMS()));
legend11->SetFillColor(kWhite);
THStack hs11("hs11","l2pt");
c3->cd(3);
sl2pt.SetLineColor(kBlue);
bl2pt.SetLineColor(kRed);
hs11.Add(&sl2pt);
hs11.Add(&bl2pt);
hs11.Draw("nostack");
legend11->Draw();

TLegend *legend12 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend12->AddEntry(&sl2eta, "Signal", "l");
legend12->AddEntry(&sl2eta, Form("Entries %.2f", sl2eta.GetEntries()));
legend12->AddEntry(&sl2eta, Form("Mean %.2f", sl2eta.GetMean()));
legend12->AddEntry(&sl2eta, Form("Stdev %.2f", sl2eta.GetRMS()));
legend12->AddEntry(&bl2eta, "Background", "l");
legend12->AddEntry(&bl2eta, Form("Entries %.2f", bl2eta.GetEntries()));
legend12->AddEntry(&bl2eta, Form("Mean %.2f", bl2eta.GetMean()));
legend12->AddEntry(&bl2eta, Form("Stdev %.2f", bl2eta.GetRMS()));
legend12->SetFillColor(kWhite);

THStack hs12("hs12","l2eta");
c3->cd(4);
sl2eta.SetLineColor(kBlue);
bl2eta.SetLineColor(kRed);
hs12.Add(&sl2eta);
hs12.Add(&bl2eta);
hs12.Draw("nostack");
legend12->Draw();

c3->Update();
canvases.push_back(c3);

// Create the fourth canvas
THStack hs13("hs13","l2phi");
TCanvas *c4 = new TCanvas("c4", "c4", 800, 800);
c4->Divide(2, 2);


TLegend *legend13 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend13->AddEntry(&sl2phi, "Signal", "l");
legend13->AddEntry(&sl2phi, Form("Entries %.2f", sl2phi.GetEntries()));
legend13->AddEntry(&sl2phi, Form("Mean %.2f", sl2phi.GetMean()));
legend13->AddEntry(&sl2phi, Form("Stdev %.2f", sl2phi.GetRMS()));
legend13->AddEntry(&bl2phi, "Background", "l");
legend13->AddEntry(&bl2phi, Form("Entries %.2f", bl2phi.GetEntries()));
legend13->AddEntry(&bl2phi, Form("Mean %.2f", bl2phi.GetRMS()));
legend13->SetFillColor(kWhite);
c4->cd(1);
sl2phi.SetLineColor(kBlue);
bl2phi.SetLineColor(kRed);
hs13.Add(&sl2phi);
hs13.Add(&bl2phi);
hs13.Draw("nostack");
legend13->Draw();


c4->cd(2);
TLegend *legend14 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend14->AddEntry(&sl3pdgid, "Signal", "l");
legend14->AddEntry(&sl3pdgid, Form("Entries %.2f", sl3pdgid.GetEntries()));
legend14->AddEntry(&sl3pdgid, Form("Mean %.2f", sl3pdgid.GetMean()));
legend14->AddEntry(&sl3pdgid, Form("Stdev %.2f", sl3pdgid.GetRMS()));
legend14->AddEntry(&bl3pdgid, "Background", "l");
legend14->AddEntry(&bl3pdgid, Form("Entries %.2f", bl3pdgid.GetEntries()));
legend14->AddEntry(&bl3pdgid, Form("Mean %.2f", bl3pdgid.GetMean()));
legend14->AddEntry(&bl3pdgid, Form("Stdev %.2f", bl3pdgid.GetRMS()));
legend14->SetFillColor(kWhite);

THStack hs14("hs14","l3pdgid");
sl3pdgid.SetLineColor(kBlue);
bl3pdgid.SetLineColor(kRed);
hs14.Add(&sl3pdgid);
hs14.Add(&bl3pdgid);
hs14.Draw("nostack");
legend14->Draw();



TLegend *legend15 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend15->AddEntry(&sl3pt, "Signal", "l");
legend15->AddEntry(&sl3pt, Form("Entries %.2f", sl3pt.GetEntries()));
legend15->AddEntry(&sl3pt, Form("Mean %.2f", sl3pt.GetMean()));
legend15->AddEntry(&sl3pt, Form("Stdev %.2f", sl3pt.GetRMS()));
legend15->AddEntry(&bl3pt, "Background", "l");
legend15->AddEntry(&bl3pt, Form("Entries %.2f", bl3pt.GetEntries()));
legend15->AddEntry(&bl3pt, Form("Mean %.2f", bl3pt.GetMean()));
legend15->AddEntry(&bl3pt, Form("Stdev %.2f", bl3pt.GetRMS()));
legend15->SetFillColor(kWhite);
THStack hs15("hs15","l3pt");
c4->cd(3);
sl3pt.SetLineColor(kBlue);
bl3pt.SetLineColor(kRed);
hs15.Add(&sl3pt);
hs15.Add(&bl3pt);
hs15.Draw("nostack");
legend15->Draw();

c4->cd(4);
TLegend *legend16 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend16->AddEntry(&sl3eta, "Signal", "l");
legend16->AddEntry(&sl3eta, Form("Entries %.2f", sl3eta.GetEntries()));
legend16->AddEntry(&sl3eta, Form("Mean %.2f", sl3eta.GetMean()));
legend16->AddEntry(&sl3eta, Form("Stdev %.2f", sl3eta.GetRMS()));
legend16->AddEntry(&bl3eta, "Background", "l");
legend16->AddEntry(&bl3eta, Form("Entries %.2f", bl3eta.GetEntries()));
legend16->AddEntry(&bl3eta, Form("Mean %.2f", bl3eta.GetMean()));
legend16->AddEntry(&bl3eta, Form("Stdev %.2f", bl3eta.GetRMS()));
legend16->SetFillColor(kWhite);

THStack hs16("hs16","l3eta");
sl3eta.SetLineColor(kBlue);
bl3eta.SetLineColor(kRed);
hs16.Add(&sl3eta);
hs16.Add(&bl3eta);
hs16.Draw("nostack");
legend16->Draw();

c4->Update();
canvases.push_back(c4);
 
// Create the fifth canvas
THStack hs17("hs17","l3phi");
TCanvas *c5 = new TCanvas("c5", "c5", 800, 800);
c5->Divide(2, 2);



c5->cd(1);

TLegend *legend17 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend17->AddEntry(&sl3phi, "Signal", "l");
legend17->AddEntry(&sl3phi, Form("Entries %.2f", sl3phi.GetEntries()));
legend17->AddEntry(&sl3phi, Form("Mean %.2f", sl3phi.GetMean()));
legend17->AddEntry(&sl3phi, Form("Stdev %.2f", sl3phi.GetRMS()));
legend17->AddEntry(&bl3phi, "Background", "l");
legend17->AddEntry(&bl3phi, Form("Entries %.2f", bl3phi.GetEntries()));
legend17->AddEntry(&bl3phi, Form("Mean %.2f", bl3phi.GetRMS()));
legend17->SetFillColor(kWhite);
sl3phi.SetLineColor(kBlue);
bl3phi.SetLineColor(kRed);
hs17.Add(&sl3phi);
hs17.Add(&bl3phi);
hs17.Draw("nostack");
legend17->Draw();


c5->cd(2);
TLegend *legend18 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend18->AddEntry(&sl4pdgid, "Signal", "l");
legend18->AddEntry(&sl4pdgid, Form("Entries %.2f", sl4pdgid.GetEntries()));
legend18->AddEntry(&sl4pdgid, Form("Mean %.2f", sl4pdgid.GetMean()));
legend18->AddEntry(&sl4pdgid, Form("Stdev %.2f", sl4pdgid.GetRMS()));
legend18->AddEntry(&bl4pdgid, "Background", "l");
legend18->AddEntry(&bl4pdgid, Form("Entries %.2f", bl4pdgid.GetEntries()));
legend18->AddEntry(&bl4pdgid, Form("Mean %.2f", bl4pdgid.GetMean()));
legend18->AddEntry(&bl4pdgid, Form("Stdev %.2f", bl4pdgid.GetRMS()));
legend18->SetFillColor(kWhite);

THStack hs18("hs18","l4pdgid");
sl4pdgid.SetLineColor(kBlue);
bl4pdgid.SetLineColor(kRed);
hs18.Add(&sl4pdgid);
hs18.Add(&bl4pdgid);
hs18.Draw("nostack");
legend18->Draw();



TLegend *legend19 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend19->AddEntry(&sl4pt, "Signal", "l");
legend19->AddEntry(&sl4pt, Form("Entries %.2f", sl4pt.GetEntries()));
legend19->AddEntry(&sl4pt, Form("Mean %.2f", sl4pt.GetMean()));
legend19->AddEntry(&sl4pt, Form("Stdev %.2f", sl4pt.GetRMS()));
legend19->AddEntry(&bl4pt, "Background", "l");
legend19->AddEntry(&bl4pt, Form("Entries %.2f", bl4pt.GetEntries()));
legend19->AddEntry(&bl4pt, Form("Mean %.2f", bl4pt.GetMean()));
legend19->AddEntry(&bl4pt, Form("Stdev %.2f", bl4pt.GetRMS()));
legend19->SetFillColor(kWhite);

THStack hs19("hs19","l4pt");
c5->cd(3);
sl4pt.SetLineColor(kBlue);
bl4pt.SetLineColor(kRed);
hs19.Add(&sl4pt);
hs19.Add(&bl4pt);
hs19.Draw("nostack");
legend19->Draw();



TLegend *legend20 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend20->AddEntry(&sl4eta, "Signal", "l");
legend20->AddEntry(&sl4eta, Form("Entries %.2f", sl4eta.GetEntries()));
legend20->AddEntry(&sl4eta, Form("Mean %.2f", sl4eta.GetMean()));
legend20->AddEntry(&sl4eta, Form("Stdev %.2f", sl4eta.GetRMS()));
legend20->AddEntry(&bl4eta, "Background", "l");
legend20->AddEntry(&bl4eta, Form("Entries %.2f", bl4eta.GetEntries()));
legend20->AddEntry(&bl4eta, Form("Mean %.2f", bl4eta.GetMean()));
legend20->AddEntry(&bl4eta, Form("Stdev %.2f", bl4eta.GetRMS()));
legend20->SetFillColor(kWhite);

THStack hs20("hs20","l4eta");
c5->cd(4);
sl4eta.SetLineColor(kBlue);
bl4eta.SetLineColor(kRed);
hs20.Add(&sl4eta);
hs20.Add(&bl4eta);
hs20.Draw("nostack");
legend20->Draw();

c5->Update();
canvases.push_back(c5);



TLegend *legend21 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend21->AddEntry(&sl4phi, "Signal", "l");
legend21->AddEntry(&sl4phi, Form("Entries %.2f", sl4phi.GetEntries()));
legend21->AddEntry(&sl4phi, Form("Mean %.2f", sl4phi.GetMean()));
legend21->AddEntry(&sl4phi, Form("Stdev %.2f", sl4phi.GetRMS()));
legend21->AddEntry(&bl4phi, "Background", "l");
legend21->AddEntry(&bl4phi, Form("Entries %.2f", bl4phi.GetEntries()));
legend21->AddEntry(&bl4phi, Form("Mean %.2f", bl4phi.GetMean()));
legend21->AddEntry(&bl4phi, Form("Stdev %.2f", bl4phi.GetRMS()));
legend21->SetFillColor(kWhite);

THStack hs21("hs21","l4phi");
TCanvas *c6 = new TCanvas("c6", "c6", 800, 800);
c6->Divide(2, 2);
c6->cd(1);
sl4phi.SetLineColor(kBlue);
bl4phi.SetLineColor(kRed);
hs21.Add(&sl4phi);
hs21.Add(&bl4phi);
hs21.Draw("nostack");
legend21->Draw();


//jet
c6->cd(2);

TLegend *legend22 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend22->AddEntry(&sj1pt, "Signal", "l");
legend22->AddEntry(&sj1pt, Form("Entries %.2f", sj1pt.GetEntries()));
legend22->AddEntry(&sj1pt, Form("Mean %.2f", sj1pt.GetMean()));
legend22->AddEntry(&sj1pt, Form("Stdev %.2f", sj1pt.GetRMS()));
legend22->AddEntry(&bj1pt, "Background", "l");
legend22->AddEntry(&bj1pt, Form("Entries %.2f", bj1pt.GetEntries()));
legend22->AddEntry(&bj1pt, Form("Mean %.2f", bj1pt.GetMean()));
legend22->AddEntry(&bj1pt, Form("Stdev %.2f", bj1pt.GetRMS()));
legend22->SetFillColor(kWhite);
THStack hs22("hs22","j1pt");
sj1pt.SetLineColor(kBlue);
bj1pt.SetLineColor(kRed);
hs22.Add(&sj1pt);
hs22.Add(&bj1pt);
hs22.Draw("nostack");
legend22->Draw();



TLegend *legend23 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend23->AddEntry(&sj1eta, "Signal", "l");
legend23->AddEntry(&sj1eta, Form("Entries %.2f", sj1eta.GetEntries()));
legend23->AddEntry(&sj1eta, Form("Mean %.2f", sj1eta.GetMean()));
legend23->AddEntry(&sj1eta, Form("Stdev %.2f", sj1eta.GetRMS()));
legend23->AddEntry(&bj1eta, "Background", "l");
legend23->AddEntry(&bj1eta, Form("Entries %.2f", bj1eta.GetEntries()));
legend23->AddEntry(&bj1eta, Form("Mean %.2f", bj1eta.GetMean()));
legend23->AddEntry(&bj1eta, Form("Stdev %.2f", bj1eta.GetRMS()));
THStack hs23("hs23","j1eta");
c6->cd(3);
sj1eta.SetLineColor(kBlue);
bj1eta.SetLineColor(kRed);
hs23.Add(&sj1eta);
hs23.Add(&bj1eta);
hs23.Draw("nostack");
legend23->Draw();


TLegend *legend24 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend24->AddEntry(&sj1phi, "Signal", "l");
legend24->AddEntry(&sj1phi, Form("Entries %.2f", sj1phi.GetEntries()));
legend24->AddEntry(&sj1phi, Form("Mean %.2f", sj1phi.GetMean()));
legend24->AddEntry(&sj1phi, Form("Stdev %.2f", sj1phi.GetRMS()));
legend24->AddEntry(&bj1phi, "Background", "l");
legend24->AddEntry(&bj1phi, Form("Entries %.2f", bj1phi.GetEntries()));
legend24->AddEntry(&bj1phi, Form("Mean %.2f", bj1phi.GetMean()));
legend24->AddEntry(&bj1phi, Form("Stdev %.2f", bj1phi.GetRMS()));
THStack hs24("hs24","j1phi");
c6->cd(4);
sj1phi.SetLineColor(kBlue);
bj1phi.SetLineColor(kRed);
hs24.Add(&sj1phi);
hs24.Add(&bj1phi);
hs24.Draw("nostack");
legend24->Draw();


c6->Update();
canvases.push_back(c6);

// Create the sixth canvas
TCanvas *c7 = new TCanvas("c7", "c7", 800, 800);
c7->Divide(2, 2);

TLegend *legend25 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend25->AddEntry(&sj1E, "Signal", "l");
legend25->AddEntry(&sj1E, Form("Entries %.2f", sj1E.GetEntries()));
legend25->AddEntry(&sj1E, Form("Mean %.2f", sj1E.GetMean()));
legend25->AddEntry(&sj1E, Form("Stdev %.2f", sj1E.GetRMS()));
legend25->AddEntry(&bj1E, "Background", "l");
legend25->AddEntry(&bj1E, Form("Entries %.2f", bj1E.GetEntries()));
legend25->AddEntry(&bj1E, Form("Mean %.2f", bj1E.GetMean()));
legend25->AddEntry(&bj1E, Form("Stdev %.2f", bj1E.GetRMS()));

c7->cd(1);
THStack hs25("hs25","j1E");
sj1E.SetLineColor(kBlue);
bj1E.SetLineColor(kRed);
hs25.Add(&sj1phi);
hs25.Add(&bj1phi);
hs25.Draw("nostack");
legend25->Draw();



TLegend *legend26 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend26->AddEntry(&sj2pt, "Signal", "l");
legend26->AddEntry(&sj2pt, Form("Entries %.2f", sj2pt.GetEntries()));
legend26->AddEntry(&sj2pt, Form("Mean %.2f", sj2pt.GetMean()));
legend26->AddEntry(&sj2pt, Form("Stdev %.2f", sj2pt.GetRMS()));
legend26->AddEntry(&bj2pt, "Background", "l");
legend26->AddEntry(&bj2pt, Form("Entries %.2f", bj2pt.GetEntries()));
legend26->AddEntry(&bj2pt, Form("Mean %.2f", bj2pt.GetMean()));
legend26->AddEntry(&bj2pt, Form("Stdev %.2f", bj2pt.GetRMS()));
legend26->SetFillColor(kWhite);
THStack hs26("hs26","j2pt");
c7->cd(2);
sj2pt.SetLineColor(kBlue);
bj2pt.SetLineColor(kRed);
hs26.Add(&sj2pt);
hs26.Add(&bj2pt);
hs26.Draw("nostack");
legend26->Draw();



TLegend *legend27 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend27->AddEntry(&sj2eta, "Signal", "l");
legend27->AddEntry(&sj2eta, Form("Entries %.2f", sj2eta.GetEntries()));
legend27->AddEntry(&sj2eta, Form("Mean %.2f", sj2eta.GetMean()));
legend27->AddEntry(&sj2eta, Form("Stdev %.2f", sj2eta.GetRMS()));
legend27->AddEntry(&bj2eta, "Background", "l");
legend27->AddEntry(&bj2eta, Form("Entries %.2f", bj2eta.GetEntries()));
legend27->AddEntry(&bj2eta, Form("Mean %.2f", bj2eta.GetMean()));
legend27->AddEntry(&bj2eta, Form("Stdev %.2f", bj2eta.GetRMS()));
THStack hs27("hs27","j2eta");
c7->cd(3);
sj2eta.SetLineColor(kBlue);
bj2eta.SetLineColor(kRed);
hs27.Add(&sj2eta);
hs27.Add(&bj2eta);
hs27.Draw("nostack");
legend27->Draw();


TLegend *legend28 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend28->AddEntry(&sj2phi, "Signal", "l");
legend28->AddEntry(&sj2phi, Form("Entries %.2f", sj2phi.GetEntries()));
legend28->AddEntry(&sj2phi, Form("Mean %.2f", sj2phi.GetMean()));
legend28->AddEntry(&sj2phi, Form("Stdev %.2f", sj2phi.GetRMS()));
legend28->AddEntry(&bj2phi, "Background", "l");
legend28->AddEntry(&bj2phi, Form("Entries %.2f", bj2phi.GetEntries()));
legend28->AddEntry(&bj2phi, Form("Mean %.2f", bj2phi.GetMean()));
legend28->AddEntry(&bj2phi, Form("Stdev %.2f", bj2phi.GetRMS()));

THStack hs28("hs28","j2phi");
c7->cd(4);
sj2phi.SetLineColor(kBlue);
bj2phi.SetLineColor(kRed);
hs28.Add(&sj2phi);
hs28.Add(&bj2phi);
hs28.Draw("nostack");
legend28->Draw();


c7->Update();
canvases.push_back(c7);



TCanvas *c8 = new TCanvas("c8", "c8", 800, 800);
c8->cd(1);
TLegend *legend29 = new TLegend(0.7, 0.7, 0.9, 0.9);
legend29->AddEntry(&sj2E, "Signal", "l");
legend29->AddEntry(&sj2E, Form("Entries %.2f", sj2E.GetEntries()));
legend29->AddEntry(&sj2E, Form("Mean %.2f", sj2E.GetMean()));
legend29->AddEntry(&sj2E, Form("Stdev %.2f", sj2E.GetRMS()));
legend29->AddEntry(&bj2E, "Background", "l");
legend29->AddEntry(&bj2E, Form("Entries %.2f", bj2E.GetEntries()));
legend29->AddEntry(&bj2E, Form("Mean %.2f", bj2E.GetMean()));
legend29->AddEntry(&bj2E, Form("Stdev %.2f", bj2E.GetRMS()));
THStack hs29("hs29","j2E");
sj2E.SetLineColor(kBlue);
bj2E.SetLineColor(kRed);
hs29.Add(&sj2E);
hs29.Add(&bj2E);
hs29.Draw("nostack");
legend29->Draw();

c8->Update();
canvases.push_back(c8);


//saving as pdf
c1->SaveAs("Atlashistogram.pdf(","pdf"); 
c2->SaveAs("Atlashistogram.pdf"); 
c3->SaveAs("Atlashistogram.pdf"); 
c4->SaveAs("Atlashistogram.pdf"); 
c5->SaveAs("Atlashistogram.pdf"); 
c6->SaveAs("Atlashistogram.pdf"); 
c7->SaveAs("Atlashistogram.pdf"); 
c8->SaveAs("Atlashistogram.pdf)","pdf"); 









std::cout << " found " << nlines << " points" << std::endl;
in.close();

f->Write();

}
