#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <iostream>
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TStyle.h>
#include <TROOT.h>
#include <sstream>
#include <TBranchElement.h>
#include <fstream>
#include <TGraphAsymmErrors.h>
#include <stdio.h>
#include <math.h>
//#include "../ApplyCalibration/ApplyCalibration.C"
#include "/home/sbhowmik/L1TauTrigger/L1TauCalibration/L1TauCalibration/L1TauCalibration/ApplyCalibration/ApplyCalibration.C"

using namespace std;

void ApplyIsolationForTurnOns(Bool_t nTTRange = kTRUE)
{
  TString fileName_In = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauCalibration_20210727/rootTree_calibratedOutput_MC_VBF_20210727.root";
  TString treeName_In = "outTreeForCalibration";
  TString fileName_LUT = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/Iso_LUTs_Options_MC_VBF_20210727.root";
  TString fileName_Out = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/hist_turnOns_2021Calibration_2021IsoLUT_MC_VBF_20210727.root";

  TFile fileIn(fileName_In.Data(),"READ");
  TTree* treeIn = (TTree*)fileIn.Get(treeName_In);
  TFile fileLUT(fileName_LUT.Data(),"READ");
  TFile fileOut(fileName_Out, "RECREATE");

  std::map<TString,TH3F*> histosIsolation;
  for(UInt_t i = 0 ; i < 101 ; ++i)
    {
      TString CurrentNameHisto = "LUT_WP";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)fileLUT.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }  

  for(UInt_t i = 1 ; i < 23 ; ++i)
    {
      TString CurrentNameHisto = "LUT_Progression_";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)fileLUT.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }  
  //TString CurrentNameHisto = "LUT_Progression_31_extrap";
  //TH3F* current_Histo = (TH3F*)fileLUT.Get(CurrentNameHisto.Data());
  //histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));

  Int_t           in_L1Tau_IEta;
  Int_t           in_L1Tau_hasEM;
  Float_t         in_Target;
  Int_t           in_L1Tau_IEt;
  Int_t           in_L1Tau_RawIEt;
  Int_t           in_EventNumber;
  Int_t           in_RunNumber;
  Int_t           in_L1Tau_nTT;
  Float_t         in_L1Tau_pt;
  Float_t         in_L1Tau_CalibPt;
  Float_t         in_OfflineTau_pt;
  Int_t           in_compressedieta;
  Int_t           in_compressedE;
  Int_t           in_L1Tau_Iso;
  Int_t           in_compressednTT;
  Int_t           in_OfflineTau_isMatched;
  Int_t           in_L1Tau_isMerged;
  Int_t           in_supercompressedE;
  Int_t           in_supercompressednTT;
  Int_t           in_L1Tau_Qual;

  treeIn->SetBranchAddress("L1Tau_IEta", &in_L1Tau_IEta);
  treeIn->SetBranchAddress("L1Tau_hasEM", &in_L1Tau_hasEM);
  treeIn->SetBranchAddress("Target", &in_Target);
  treeIn->SetBranchAddress("L1Tau_IEt", &in_L1Tau_IEt);
  treeIn->SetBranchAddress("L1Tau_RawIEt", &in_L1Tau_RawIEt);
  treeIn->SetBranchAddress("EventNumber", &in_EventNumber);
  treeIn->SetBranchAddress("RunNumber", &in_RunNumber);
  treeIn->SetBranchAddress("L1Tau_nTT", &in_L1Tau_nTT);
  treeIn->SetBranchAddress("L1Tau_pt", &in_L1Tau_pt);
  treeIn->SetBranchAddress("L1Tau_CalibPt", &in_L1Tau_CalibPt);
  treeIn->SetBranchAddress("OfflineTau_pt", &in_OfflineTau_pt);
  treeIn->SetBranchAddress("compressedieta", &in_compressedieta);
  treeIn->SetBranchAddress("compressedE", &in_compressedE);
  treeIn->SetBranchAddress("L1Tau_Iso", &in_L1Tau_Iso);
  treeIn->SetBranchAddress("compressednTT", &in_compressednTT);
  treeIn->SetBranchAddress("OfflineTau_isMatched", &in_OfflineTau_isMatched);
  treeIn->SetBranchAddress("L1Tau_isMerged", &in_L1Tau_isMerged);
  treeIn->SetBranchAddress("supercompressedE", &in_supercompressedE);
  treeIn->SetBranchAddress("supercompressednTT", &in_supercompressednTT);
  treeIn->SetBranchAddress("L1Tau_Qual",&in_L1Tau_Qual);

  Double_t binning[22] = {18,20,22,24,26,28,30,32,35,40,45,50,60,70,90,110,210,350,500,700,1000,2000};
  TH1F* pt = new TH1F("pt","pt",21,binning);
  TH1F* pt_pass_noIso   = new TH1F("pt_pass_noIso"  ,"pt_pass_noIso"  ,21,binning);
  TH1F* pt_pass_Option1   = new TH1F("pt_pass_Option1"  ,"pt_pass_Option1"  ,21,binning);
  TH1F* pt_pass_Option2   = new TH1F("pt_pass_Option2"  ,"pt_pass_Option2"  ,21,binning);
  TH1F* pt_pass_Option3   = new TH1F("pt_pass_Option3"  ,"pt_pass_Option3"  ,21,binning);
  TH1F* pt_pass_Option4   = new TH1F("pt_pass_Option4"  ,"pt_pass_Option4"  ,21,binning);
  TH1F* pt_pass_Option5   = new TH1F("pt_pass_Option5"  ,"pt_pass_Option5"  ,21,binning);
  TH1F* pt_pass_Option6   = new TH1F("pt_pass_Option6"  ,"pt_pass_Option6"  ,21,binning);
  TH1F* pt_pass_Option7   = new TH1F("pt_pass_Option7"  ,"pt_pass_Option7"  ,21,binning);
  TH1F* pt_pass_Option8   = new TH1F("pt_pass_Option8"  ,"pt_pass_Option8"  ,21,binning);
  TH1F* pt_pass_Option9   = new TH1F("pt_pass_Option9"  ,"pt_pass_Option9"  ,21,binning);
  TH1F* pt_pass_Option10  = new TH1F("pt_pass_Option10" ,"pt_pass_Option10" ,21,binning);
  TH1F* pt_pass_Option11  = new TH1F("pt_pass_Option11" ,"pt_pass_Option11" ,21,binning);
  TH1F* pt_pass_Option12  = new TH1F("pt_pass_Option12" ,"pt_pass_Option12" ,21,binning);
  TH1F* pt_pass_Option13  = new TH1F("pt_pass_Option13" ,"pt_pass_Option13" ,21,binning);
  TH1F* pt_pass_Option14  = new TH1F("pt_pass_Option14" ,"pt_pass_Option14" ,21,binning);
  TH1F* pt_pass_Option15  = new TH1F("pt_pass_Option15" ,"pt_pass_Option15" ,21,binning);
  TH1F* pt_pass_Option16  = new TH1F("pt_pass_Option16" ,"pt_pass_Option16" ,21,binning);
  TH1F* pt_pass_Option17  = new TH1F("pt_pass_Option17" ,"pt_pass_Option17" ,21,binning);
  TH1F* pt_pass_Option18  = new TH1F("pt_pass_Option18" ,"pt_pass_Option18" ,21,binning);
  TH1F* pt_pass_Option19  = new TH1F("pt_pass_Option19" ,"pt_pass_Option19" ,21,binning);
  TH1F* pt_pass_Option20  = new TH1F("pt_pass_Option20" ,"pt_pass_Option20" ,21,binning);
  TH1F* pt_pass_Option21  = new TH1F("pt_pass_Option21" ,"pt_pass_Option21" ,21,binning);
  TH1F* pt_pass_Option22  = new TH1F("pt_pass_Option22" ,"pt_pass_Option22" ,21,binning);
  TH1F* pt_pass_Option31_extrap  = new TH1F("pt_pass_Option31_extrap" ,"pt_pass_Option31_extrap" ,21,binning);

  Double_t Threshold_NewLayer1_noIso   = 45.51;
  Double_t Threshold_NewLayer1_Option1 = 44.51;
  Double_t Threshold_NewLayer1_Option2 = 44.51;
  Double_t Threshold_NewLayer1_Option3 = 44.51;
  Double_t Threshold_NewLayer1_Option4 = 45.51;
  Double_t Threshold_NewLayer1_Option5 = 45.51;
  Double_t Threshold_NewLayer1_Option6 = 45.51;
  Double_t Threshold_NewLayer1_Option7 = 45.51;
  Double_t Threshold_NewLayer1_Option8 = 34.51;
  Double_t Threshold_NewLayer1_Option9 = 45.51;
  Double_t Threshold_NewLayer1_Option10 = 45.51;
  Double_t Threshold_NewLayer1_Option11 = 45.51;
  Double_t Threshold_NewLayer1_Option12 = 45.51;
  Double_t Threshold_NewLayer1_Option13 = 45.51;
  Double_t Threshold_NewLayer1_Option14 = 45.51;
  Double_t Threshold_NewLayer1_Option15 = 45.51;
  Double_t Threshold_NewLayer1_Option16 = 45.51;
  Double_t Threshold_NewLayer1_Option17 = 45.51;
  Double_t Threshold_NewLayer1_Option18 = 45.51;
  Double_t Threshold_NewLayer1_Option19 = 45.51;
  Double_t Threshold_NewLayer1_Option20 = 45.51;
  Double_t Threshold_NewLayer1_Option21 = 45.51;
  Double_t Threshold_NewLayer1_Option22 = 34.51;
  Double_t Threshold_NewLayer1_Option31_extrap = -0.49;
  /*
  Double_t Threshold_NewLayer1_noIso   = 37.51;
  Double_t Threshold_NewLayer1_Option1 = 25.51;
  Double_t Threshold_NewLayer1_Option2 = 29.51;
  Double_t Threshold_NewLayer1_Option3 = 30.51;
  Double_t Threshold_NewLayer1_Option4 = 31.51;
  Double_t Threshold_NewLayer1_Option5 = 32.51;
  Double_t Threshold_NewLayer1_Option6 = 35.51;
  Double_t Threshold_NewLayer1_Option7 = 35.51;
  Double_t Threshold_NewLayer1_Option8 = 27.51;
  Double_t Threshold_NewLayer1_Option9 = 35.51;
  Double_t Threshold_NewLayer1_Option10 = 35.51;
  Double_t Threshold_NewLayer1_Option11 = 36.51;
  Double_t Threshold_NewLayer1_Option12 = 37.51;
  Double_t Threshold_NewLayer1_Option13 = 37.51;
  Double_t Threshold_NewLayer1_Option14 = 37.51;
  Double_t Threshold_NewLayer1_Option15 = 33.51;
  Double_t Threshold_NewLayer1_Option16 = 37.51;
  Double_t Threshold_NewLayer1_Option17 = 37.51;
  Double_t Threshold_NewLayer1_Option18 = 37.51;
  Double_t Threshold_NewLayer1_Option19 = 37.51;
  Double_t Threshold_NewLayer1_Option20 = 37.51;
  Double_t Threshold_NewLayer1_Option21 = 34.51;
  Double_t Threshold_NewLayer1_Option22 = 28.51;
  Double_t Threshold_NewLayer1_Option31_extrap = 29.51;
  */

  map<int, int> remap;
  remap[0] = 6 ;
  remap[1] = 5 ;
  remap[2] = 1 ;
  remap[3] = 0 ;
  remap[4] = 4 ;
  remap[5] = 3 ;
  remap[6] = 2 ;
  
  for(UInt_t i = 0 ; i < treeIn->GetEntries() ; ++i)
    {
      treeIn->GetEntry(i);
      if(in_L1Tau_nTT<60 && nTTRange) continue;

      pt->Fill(in_OfflineTau_pt);
      Int_t Cut_L1Tau_Iso_Option1   = histosIsolation["LUT_Progression_1"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option2   = histosIsolation["LUT_Progression_2"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option3   = histosIsolation["LUT_Progression_3"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option4   = histosIsolation["LUT_Progression_4"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option5   = histosIsolation["LUT_Progression_5"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option6   = histosIsolation["LUT_Progression_6"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option7   = histosIsolation["LUT_Progression_7"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option8   = histosIsolation["LUT_Progression_8"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option9   = histosIsolation["LUT_Progression_9"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option10  = histosIsolation["LUT_Progression_10"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option11  = histosIsolation["LUT_Progression_11"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option12  = histosIsolation["LUT_Progression_12"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option13  = histosIsolation["LUT_Progression_13"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option14  = histosIsolation["LUT_Progression_14"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option15  = histosIsolation["LUT_Progression_15"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option16  = histosIsolation["LUT_Progression_16"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option17  = histosIsolation["LUT_Progression_17"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option18  = histosIsolation["LUT_Progression_18"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option19  = histosIsolation["LUT_Progression_19"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option20  = histosIsolation["LUT_Progression_20"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option21  = histosIsolation["LUT_Progression_21"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option22  = histosIsolation["LUT_Progression_22"]->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      //Int_t Cut_L1Tau_Iso_Option31_extrap  = histosIsolation["LUT_Progression_31_extrap"]->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
	
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_noIso) pt_pass_noIso->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option1 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option1) pt_pass_Option1->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option2 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option2) pt_pass_Option2->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option3 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option3) pt_pass_Option3->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option4 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option4) pt_pass_Option4->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option5 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option5) pt_pass_Option5->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option6 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option6) pt_pass_Option6->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option7 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option7) pt_pass_Option7->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option8 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option8) pt_pass_Option8->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option9 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option9) pt_pass_Option9->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option10 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option10) pt_pass_Option10->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option11 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option11) pt_pass_Option11->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option12 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option12) pt_pass_Option12->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option13 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option13) pt_pass_Option13->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option14 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option14) pt_pass_Option14->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option15 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option15) pt_pass_Option15->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option16 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option16) pt_pass_Option16->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option17 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option17) pt_pass_Option17->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option18 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option18) pt_pass_Option18->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option19 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option19) pt_pass_Option19->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option20 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option20) pt_pass_Option20->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option21 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option21) pt_pass_Option21->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option22 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option22) pt_pass_Option22->Fill(in_OfflineTau_pt);
      //if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option31_extrap && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option31_extrap) pt_pass_Option31_extrap->Fill(in_OfflineTau_pt);
    }

  TGraphAsymmErrors* turnOn_noIso = new TGraphAsymmErrors(pt_pass_noIso,pt,"cp");
  turnOn_noIso->Write();

  TGraphAsymmErrors* turnOn_Option1 = new TGraphAsymmErrors(pt_pass_Option1,pt,"cp");
  turnOn_Option1->Write();

  TGraphAsymmErrors* turnOn_Option2 = new TGraphAsymmErrors(pt_pass_Option2,pt,"cp");
  turnOn_Option2->Write();

  TGraphAsymmErrors* turnOn_Option3 = new TGraphAsymmErrors(pt_pass_Option3,pt,"cp");
  turnOn_Option3->Write();

  TGraphAsymmErrors* turnOn_Option4 = new TGraphAsymmErrors(pt_pass_Option4,pt,"cp");
  turnOn_Option4->Write();

  TGraphAsymmErrors* turnOn_Option5 = new TGraphAsymmErrors(pt_pass_Option5,pt,"cp");
  turnOn_Option5->Write();

  TGraphAsymmErrors* turnOn_Option6 = new TGraphAsymmErrors(pt_pass_Option6,pt,"cp");
  turnOn_Option6->Write();

  TGraphAsymmErrors* turnOn_Option7 = new TGraphAsymmErrors(pt_pass_Option7,pt,"cp");
  turnOn_Option7->Write();

  TGraphAsymmErrors* turnOn_Option8 = new TGraphAsymmErrors(pt_pass_Option8,pt,"cp");
  turnOn_Option8->Write();

  TGraphAsymmErrors* turnOn_Option9 = new TGraphAsymmErrors(pt_pass_Option9,pt,"cp");
  turnOn_Option9->Write();

  TGraphAsymmErrors* turnOn_Option10 = new TGraphAsymmErrors(pt_pass_Option10,pt,"cp");
  turnOn_Option10->Write();

  TGraphAsymmErrors* turnOn_Option11 = new TGraphAsymmErrors(pt_pass_Option11,pt,"cp");
  turnOn_Option11->Write();

  TGraphAsymmErrors* turnOn_Option12 = new TGraphAsymmErrors(pt_pass_Option12,pt,"cp");
  turnOn_Option12->Write();

  TGraphAsymmErrors* turnOn_Option13 = new TGraphAsymmErrors(pt_pass_Option13,pt,"cp");
  turnOn_Option13->Write();

  TGraphAsymmErrors* turnOn_Option14 = new TGraphAsymmErrors(pt_pass_Option14,pt,"cp");
  turnOn_Option14->Write();

  TGraphAsymmErrors* turnOn_Option15 = new TGraphAsymmErrors(pt_pass_Option15,pt,"cp");
  turnOn_Option15->Write();

  TGraphAsymmErrors* turnOn_Option16 = new TGraphAsymmErrors(pt_pass_Option16,pt,"cp");
  turnOn_Option16->Write();

  TGraphAsymmErrors* turnOn_Option17 = new TGraphAsymmErrors(pt_pass_Option17,pt,"cp");
  turnOn_Option17->Write();

  TGraphAsymmErrors* turnOn_Option18 = new TGraphAsymmErrors(pt_pass_Option18,pt,"cp");
  turnOn_Option18->Write();

  TGraphAsymmErrors* turnOn_Option19 = new TGraphAsymmErrors(pt_pass_Option19,pt,"cp");
  turnOn_Option19->Write();

  TGraphAsymmErrors* turnOn_Option20 = new TGraphAsymmErrors(pt_pass_Option20,pt,"cp");
  turnOn_Option20->Write();

  TGraphAsymmErrors* turnOn_Option21 = new TGraphAsymmErrors(pt_pass_Option21,pt,"cp");
  turnOn_Option21->Write();

  TGraphAsymmErrors* turnOn_Option22 = new TGraphAsymmErrors(pt_pass_Option22,pt,"cp");
  turnOn_Option22->Write();

  TGraphAsymmErrors* turnOn_Option31_extrap = new TGraphAsymmErrors(pt_pass_Option31_extrap,pt,"cp");
  turnOn_Option31_extrap->Write();

}
