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
//#include "../ApplyCalibration/ApplyCalibration.C"
#include "/home/sbhowmik/L1TauTrigger/L1TauCalibration/L1TauCalibration/L1TauCalibration/ApplyCalibration/ApplyCalibration.C"
#include <map>

using namespace std;

void rate_Calculation()
{
  TString fileName_In = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/rootTree_calibratedOutputZeroBias_MC_SingleNeutrino_20210727.root";
  TString treeName_In = "outTreeForCalibration";
  TString fileName_LUT = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/Iso_LUTs_Options_MC_VBF_20210727.root";
  TString fileName_Out = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/hist_rate_calibratedOutputZeroBias_MC_SingleNeutrino_Iso_LUT_Option_20210727.root";

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
  TString CurrentNameHisto = "LUT_Progression_31_extrap";
  TH3F* current_Histo = (TH3F*)fileLUT.Get(CurrentNameHisto.Data());
  histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));

  Int_t       in_EventNumber =  0;
  Int_t           in_RunNumber =  0;
  Int_t           in_lumi =  0;
  vector<float>   *in_l1tEmuPt =  0;
  vector<float>   *in_l1tEmuEta =  0;
  vector<float>   *in_l1tEmuPhi =  0;
  vector<int>     *in_l1tEmuQual =  0;
  vector<int>     *in_l1tEmuNTT =  0;
  vector<int>     *in_l1tEmuHasEM =  0;
  vector<int>     *in_l1tEmuIsMerged =  0;
  vector<int>     *in_l1tEmuTowerIEta =  0;
  vector<int>     *in_l1tEmuTowerIPhi =  0;
  vector<int>     *in_l1tEmuRawEt =  0;
  vector<int>     *in_l1tEmuIsoEt =  0;
  vector<int>     *in_compressedieta =  0;
  vector<int>     *in_compressedE =  0;
  vector<int>     *in_compressednTT =  0;
  vector<int>     *in_supercompressedE =  0;
  vector<int>     *in_supercompressednTT =  0;
  vector<float>   *in_CalibPt =  0;

  treeIn->SetBranchAddress("EventNumber", &in_EventNumber);
  treeIn->SetBranchAddress("RunNumber", &in_RunNumber);
  treeIn->SetBranchAddress("lumi", &in_lumi);
  treeIn->SetBranchAddress("L1Tau_pt",&in_l1tEmuPt);
  treeIn->SetBranchAddress("L1Tau_eta",&in_l1tEmuEta);
  treeIn->SetBranchAddress("L1Tau_phi",&in_l1tEmuPhi);
  treeIn->SetBranchAddress("L1Tau_Qual",&in_l1tEmuQual);
  treeIn->SetBranchAddress("L1Tau_nTT",&in_l1tEmuNTT);
  treeIn->SetBranchAddress("L1Tau_hasEM",&in_l1tEmuHasEM);
  treeIn->SetBranchAddress("L1Tau_isMerged",&in_l1tEmuIsMerged);
  treeIn->SetBranchAddress("L1Tau_IEt",&in_l1tEmuRawEt);
  treeIn->SetBranchAddress("L1Tau_Iso",&in_l1tEmuIsoEt);
  treeIn->SetBranchAddress("L1Tau_IEta",&in_l1tEmuTowerIEta);
  treeIn->SetBranchAddress("L1Tau_IPhi",&in_l1tEmuTowerIPhi);
  treeIn->SetBranchAddress("compressedieta",&in_compressedieta);
  treeIn->SetBranchAddress("compressedE",&in_compressedE);
  treeIn->SetBranchAddress("compressednTT",&in_compressednTT);
  treeIn->SetBranchAddress("supercompressedE",&in_supercompressedE);
  treeIn->SetBranchAddress("supercompressednTT",&in_supercompressednTT);
  treeIn->SetBranchAddress("L1Tau_CalibPt",&in_CalibPt);

  TH1F* pt_Progression_1 = new TH1F("pt_Progression_1","pt_Progression_1",240,0.,240.);
  TH1F* pt_Progression_2 = new TH1F("pt_Progression_2","pt_Progression_2",240,0.,240.);
  TH1F* pt_Progression_3 = new TH1F("pt_Progression_3","pt_Progression_3",240,0.,240.);
  TH1F* pt_Progression_4 = new TH1F("pt_Progression_4","pt_Progression_4",240,0.,240.);
  TH1F* pt_Progression_5 = new TH1F("pt_Progression_5","pt_Progression_5",240,0.,240.);
  TH1F* pt_Progression_6 = new TH1F("pt_Progression_6","pt_Progression_6",240,0.,240.);
  TH1F* pt_Progression_7 = new TH1F("pt_Progression_7","pt_Progression_7",240,0.,240.);
  TH1F* pt_Progression_8 = new TH1F("pt_Progression_8","pt_Progression_8",240,0.,240.);
  TH1F* pt_Progression_9 = new TH1F("pt_Progression_9","pt_Progression_9",240,0.,240.);
  TH1F* pt_Progression_10 = new TH1F("pt_Progression_10","pt_Progression_10",240,0.,240.);
  TH1F* pt_Progression_11 = new TH1F("pt_Progression_11","pt_Progression_11",240,0.,240.);
  TH1F* pt_Progression_12 = new TH1F("pt_Progression_12","pt_Progression_12",240,0.,240.);
  TH1F* pt_Progression_13 = new TH1F("pt_Progression_13","pt_Progression_13",240,0.,240.);
  TH1F* pt_Progression_14 = new TH1F("pt_Progression_14","pt_Progression_14",240,0.,240.);
  TH1F* pt_Progression_15 = new TH1F("pt_Progression_15","pt_Progression_15",240,0.,240.);
  TH1F* pt_Progression_16 = new TH1F("pt_Progression_16","pt_Progression_16",240,0.,240.);
  TH1F* pt_Progression_17 = new TH1F("pt_Progression_17","pt_Progression_17",240,0.,240.);
  TH1F* pt_Progression_18 = new TH1F("pt_Progression_18","pt_Progression_18",240,0.,240.);
  TH1F* pt_Progression_19 = new TH1F("pt_Progression_19","pt_Progression_19",240,0.,240.);
  TH1F* pt_Progression_20 = new TH1F("pt_Progression_20","pt_Progression_20",240,0.,240.);
  TH1F* pt_Progression_21 = new TH1F("pt_Progression_21","pt_Progression_21",240,0.,240.);
  TH1F* pt_Progression_22 = new TH1F("pt_Progression_22","pt_Progression_22",240,0.,240.);
  TH1F* pt_Progression_31_extrap = new TH1F("pt_Progression_31_extrap","pt_Progression_31_extrap",240,0.,240.);

  TH2F* pt_IsoInf_DiTau = new TH2F("pt_IsoInf_DiTau","pt_IsoInf_DiTau",240,0.,240.,240,0.,240.);

  TH2F* pt_DiTau_Progression_1 = new TH2F("pt_DiTau_Progression_1","pt_DiTau_Progression_1",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_2 = new TH2F("pt_DiTau_Progression_2","pt_DiTau_Progression_2",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_3 = new TH2F("pt_DiTau_Progression_3","pt_DiTau_Progression_3",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_4 = new TH2F("pt_DiTau_Progression_4","pt_DiTau_Progression_4",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_5 = new TH2F("pt_DiTau_Progression_5","pt_DiTau_Progression_5",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_6 = new TH2F("pt_DiTau_Progression_6","pt_DiTau_Progression_6",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_7 = new TH2F("pt_DiTau_Progression_7","pt_DiTau_Progression_7",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_8 = new TH2F("pt_DiTau_Progression_8","pt_DiTau_Progression_8",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_9 = new TH2F("pt_DiTau_Progression_9","pt_DiTau_Progression_9",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_10 = new TH2F("pt_DiTau_Progression_10","pt_DiTau_Progression_10",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_11 = new TH2F("pt_DiTau_Progression_11","pt_DiTau_Progression_11",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_12 = new TH2F("pt_DiTau_Progression_12","pt_DiTau_Progression_12",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_13 = new TH2F("pt_DiTau_Progression_13","pt_DiTau_Progression_13",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_14 = new TH2F("pt_DiTau_Progression_14","pt_DiTau_Progression_14",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_15 = new TH2F("pt_DiTau_Progression_15","pt_DiTau_Progression_15",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_16 = new TH2F("pt_DiTau_Progression_16","pt_DiTau_Progression_16",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_17 = new TH2F("pt_DiTau_Progression_17","pt_DiTau_Progression_17",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_18 = new TH2F("pt_DiTau_Progression_18","pt_DiTau_Progression_18",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_19 = new TH2F("pt_DiTau_Progression_19","pt_DiTau_Progression_19",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_20 = new TH2F("pt_DiTau_Progression_20","pt_DiTau_Progression_20",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_21 = new TH2F("pt_DiTau_Progression_21","pt_DiTau_Progression_21",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_22 = new TH2F("pt_DiTau_Progression_22","pt_DiTau_Progression_22",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_31_extrap = new TH2F("pt_DiTau_Progression_31_extrap","pt_DiTau_Progression_31_extrap",240,0.,240.,240,0.,240.);//

  TH1F* pt_Stage1 = new TH1F("pt_Stage1","pt_Stage1",240,0.,240.);

  Int_t Denominator = 0;

  cout<<"begin loop"<<endl;


  map<int, int> remap;
  remap[0] = 6 ;
  remap[1] = 5 ;
  remap[2] = 1 ;
  remap[3] = 0 ;
  remap[4] = 4 ;
  remap[5] = 3 ;
  remap[6] = 2 ;


  //for(UInt_t i = 0 ; i < 2000000 ; ++i)

  int CounterPass = 0;
  int CounterFail = 0;
  int CounterAll = 0;

  int DiTauCounterPass = 0;
  int DiTauCounterFail = 0;
  int DiTauCounterAll = 0;

  // for(UInt_t i = 0 ; i < 3000000 ; ++i)
  for(UInt_t i = 0 ; i < treeIn->GetEntries() ; ++i)
    {
      treeIn->GetEntry(i);
      if(i%10000==0) cout<<"Entry #"<<i<<endl; 

      if(in_lumi<60 || in_lumi>455) continue;

      Float_t weight = 1.;

      ++Denominator;
      //if(in_lumi==157){      
      //std::cout << "EventNumber "<<in_EventNumber<<" RunNumber "<<in_RunNumber<<" lumi "<<in_lumi<<" L1Tau_pt "<<in_l1tEmuPt->at(0)<<" L1Tau_Iso "<<in_l1tEmuIsoEt->at(0)<<std::endl;
      //std::cout<<" L1Tau_CalibPt "<<in_CalibPt->at(0)<<" L1Tau_eta "<<in_l1tEmuEta->at(0)<<" L1Tau_phi "<<in_l1tEmuPhi->at(0)<<" L1Tau_IEt "<<in_l1tEmuRawEt->at(0)<<std::endl;
      //}

      bool Filled_IsoInf = kFALSE;

      bool Filled_Progression_1 = kFALSE;
      bool Filled_Progression_2 = kFALSE;
      bool Filled_Progression_3 = kFALSE;
      bool Filled_Progression_4 = kFALSE;
      bool Filled_Progression_5 = kFALSE;
      bool Filled_Progression_6 = kFALSE;
      bool Filled_Progression_7 = kFALSE;
      bool Filled_Progression_8 = kFALSE;
      bool Filled_Progression_9 = kFALSE;
      bool Filled_Progression_10 = kFALSE;
      bool Filled_Progression_11 = kFALSE;
      bool Filled_Progression_12 = kFALSE;
      bool Filled_Progression_13 = kFALSE;
      bool Filled_Progression_14 = kFALSE;
      bool Filled_Progression_15 = kFALSE;
      bool Filled_Progression_16 = kFALSE;
      bool Filled_Progression_17 = kFALSE;
      bool Filled_Progression_18 = kFALSE;
      bool Filled_Progression_19 = kFALSE;
      bool Filled_Progression_20 = kFALSE;
      bool Filled_Progression_21 = kFALSE;
      bool Filled_Progression_22 = kFALSE;
      bool Filled_Progression_31_extrap = kFALSE;

      std::vector<Int_t> Index_Taus_IsoInf;
      Index_Taus_IsoInf.push_back(-1); Index_Taus_IsoInf.push_back(-1);
      std::vector<Float_t> pt_Taus_IsoInf;
      pt_Taus_IsoInf.push_back(-99.); pt_Taus_IsoInf.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_1;
      Index_Taus_Progression_1.push_back(-1); Index_Taus_Progression_1.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_1;
      pt_Taus_Progression_1.push_back(-99.); pt_Taus_Progression_1.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_2;
      Index_Taus_Progression_2.push_back(-1); Index_Taus_Progression_2.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_2;
      pt_Taus_Progression_2.push_back(-99.); pt_Taus_Progression_2.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_3;
      Index_Taus_Progression_3.push_back(-1); Index_Taus_Progression_3.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_3;
      pt_Taus_Progression_3.push_back(-99.); pt_Taus_Progression_3.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_4;
      Index_Taus_Progression_4.push_back(-1); Index_Taus_Progression_4.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_4;
      pt_Taus_Progression_4.push_back(-99.); pt_Taus_Progression_4.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_5;
      Index_Taus_Progression_5.push_back(-1); Index_Taus_Progression_5.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_5;
      pt_Taus_Progression_5.push_back(-99.); pt_Taus_Progression_5.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_6;
      Index_Taus_Progression_6.push_back(-1); Index_Taus_Progression_6.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_6;
      pt_Taus_Progression_6.push_back(-99.); pt_Taus_Progression_6.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_7;
      Index_Taus_Progression_7.push_back(-1); Index_Taus_Progression_7.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_7;
      pt_Taus_Progression_7.push_back(-99.); pt_Taus_Progression_7.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_8;
      Index_Taus_Progression_8.push_back(-1); Index_Taus_Progression_8.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_8;
      pt_Taus_Progression_8.push_back(-99.); pt_Taus_Progression_8.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_9;
      Index_Taus_Progression_9.push_back(-1); Index_Taus_Progression_9.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_9;
      pt_Taus_Progression_9.push_back(-99.); pt_Taus_Progression_9.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_10;
      Index_Taus_Progression_10.push_back(-1); Index_Taus_Progression_10.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_10;
      pt_Taus_Progression_10.push_back(-99.); pt_Taus_Progression_10.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_11;
      Index_Taus_Progression_11.push_back(-1); Index_Taus_Progression_11.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_11;
      pt_Taus_Progression_11.push_back(-99.); pt_Taus_Progression_11.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_12;
      Index_Taus_Progression_12.push_back(-1); Index_Taus_Progression_12.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_12;
      pt_Taus_Progression_12.push_back(-99.); pt_Taus_Progression_12.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_13;
      Index_Taus_Progression_13.push_back(-1); Index_Taus_Progression_13.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_13;
      pt_Taus_Progression_13.push_back(-99.); pt_Taus_Progression_13.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_14;
      Index_Taus_Progression_14.push_back(-1); Index_Taus_Progression_14.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_14;
      pt_Taus_Progression_14.push_back(-99.); pt_Taus_Progression_14.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_15;
      Index_Taus_Progression_15.push_back(-1); Index_Taus_Progression_15.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_15;
      pt_Taus_Progression_15.push_back(-99.); pt_Taus_Progression_15.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_16;
      Index_Taus_Progression_16.push_back(-1); Index_Taus_Progression_16.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_16;
      pt_Taus_Progression_16.push_back(-99.); pt_Taus_Progression_16.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_17;
      Index_Taus_Progression_17.push_back(-1); Index_Taus_Progression_17.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_17;
      pt_Taus_Progression_17.push_back(-99.); pt_Taus_Progression_17.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_18;
      Index_Taus_Progression_18.push_back(-1); Index_Taus_Progression_18.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_18;
      pt_Taus_Progression_18.push_back(-99.); pt_Taus_Progression_18.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_19;
      Index_Taus_Progression_19.push_back(-1); Index_Taus_Progression_19.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_19;
      pt_Taus_Progression_19.push_back(-99.); pt_Taus_Progression_19.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_20;
      Index_Taus_Progression_20.push_back(-1); Index_Taus_Progression_20.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_20;
      pt_Taus_Progression_20.push_back(-99.); pt_Taus_Progression_20.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_21;
      Index_Taus_Progression_21.push_back(-1); Index_Taus_Progression_21.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_21;
      pt_Taus_Progression_21.push_back(-99.); pt_Taus_Progression_21.push_back(-99.);
      std::vector<Float_t> eta_Taus_Progression_21;
      eta_Taus_Progression_21.push_back(-99.); eta_Taus_Progression_21.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_22;
      Index_Taus_Progression_22.push_back(-1); Index_Taus_Progression_22.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_22;
      pt_Taus_Progression_22.push_back(-99.); pt_Taus_Progression_22.push_back(-99.);
      std::vector<Float_t> eta_Taus_Progression_22;
      eta_Taus_Progression_22.push_back(-99.); eta_Taus_Progression_22.push_back(-99.);
      std::vector<Int_t> isMerged_Taus_Progression_22;
      isMerged_Taus_Progression_22.push_back(-99.); isMerged_Taus_Progression_22.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_31_extrap;
      Index_Taus_Progression_31_extrap.push_back(-1); Index_Taus_Progression_31_extrap.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_31_extrap;
      pt_Taus_Progression_31_extrap.push_back(-99.); pt_Taus_Progression_31_extrap.push_back(-99.);
      std::vector<Float_t> eta_Taus_Progression_31_extrap;
      eta_Taus_Progression_31_extrap.push_back(-99.); eta_Taus_Progression_31_extrap.push_back(-99.);
      std::vector<Int_t> isMerged_Taus_Progression_31_extrap;
      isMerged_Taus_Progression_31_extrap.push_back(-99.); isMerged_Taus_Progression_31_extrap.push_back(-99.);


      for(UInt_t iL1Tau = 0 ; iL1Tau < in_CalibPt->size() ; ++iL1Tau)
	{
	  if(fabs(in_l1tEmuEta->at(iL1Tau))>2.1) continue;

	  //if(in_EventNumber==216539683 && in_lumi==157){
	  //std::cout << "EventNumber "<<in_EventNumber<<" RunNumber "<<in_RunNumber<<" lumi "<<in_lumi<<" L1Tau_pt "<<in_l1tEmuPt->at(iL1Tau)<<" L1Tau_Iso "<<in_l1tEmuIsoEt->at(iL1Tau)<<std::endl;
	  //std::cout<<" L1Tau_CalibPt "<<in_CalibPt->at(iL1Tau)<<" L1Tau_eta "<<in_l1tEmuEta->at(iL1Tau)<<" L1Tau_phi "<<in_l1tEmuPhi->at(iL1Tau)<<" L1Tau_IEt "<<in_l1tEmuRawEt->at(iL1Tau)<<std::endl;
	  //}

	  TString Result_Progression_1 = "LUT_Progression_1";
	  Int_t IsoCut_Progression_1 = histosIsolation[Result_Progression_1]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_1 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_1)
	    {
	      pt_Progression_1->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_1 = kTRUE;
	    }

	  TString Result_Progression_2 = "LUT_Progression_2";
	  Int_t IsoCut_Progression_2 = histosIsolation[Result_Progression_2]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_2 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_2)
	    {
	      pt_Progression_2->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_2 = kTRUE;
	    }

	  TString Result_Progression_3 = "LUT_Progression_3";
	  Int_t IsoCut_Progression_3 = histosIsolation[Result_Progression_3]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_3 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_3)
	    {
	      pt_Progression_3->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_3 = kTRUE;
	    }

	  TString Result_Progression_4 = "LUT_Progression_4";
	  Int_t IsoCut_Progression_4 = histosIsolation[Result_Progression_4]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_4 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_4)
	    {
	      pt_Progression_4->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_4 = kTRUE;
	    }

	  TString Result_Progression_5 = "LUT_Progression_5";
	  Int_t IsoCut_Progression_5 = histosIsolation[Result_Progression_5]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_5 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_5)
	    {
	      pt_Progression_5->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_5 = kTRUE;
	    }

	  TString Result_Progression_6 = "LUT_Progression_6";
	  Int_t IsoCut_Progression_6 = histosIsolation[Result_Progression_6]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_6 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_6)
	    {
	      pt_Progression_6->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_6 = kTRUE;
	    }

	  TString Result_Progression_7 = "LUT_Progression_7";
	  Int_t IsoCut_Progression_7 = histosIsolation[Result_Progression_7]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_7 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_7)
	    {
	      pt_Progression_7->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_7 = kTRUE;
	    }

	  TString Result_Progression_8 = "LUT_Progression_8";
	  Int_t IsoCut_Progression_8 = histosIsolation[Result_Progression_8]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_8 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_8)
	    {
	      pt_Progression_8->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_8 = kTRUE;
	    }

	  TString Result_Progression_9 = "LUT_Progression_9";
	  Int_t IsoCut_Progression_9 = histosIsolation[Result_Progression_9]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_9 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_9)
	    {
	      pt_Progression_9->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_9 = kTRUE;
	    }

	  TString Result_Progression_10 = "LUT_Progression_10";
	  Int_t IsoCut_Progression_10 = histosIsolation[Result_Progression_10]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_10 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_10)
	    {
	      pt_Progression_10->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_10 = kTRUE;
	    }

	  TString Result_Progression_11 = "LUT_Progression_11";
	  Int_t IsoCut_Progression_11 = histosIsolation[Result_Progression_11]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_11 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_11)
	    {
	      pt_Progression_11->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_11 = kTRUE;
	    }

	  TString Result_Progression_12 = "LUT_Progression_12";
	  Int_t IsoCut_Progression_12 = histosIsolation[Result_Progression_12]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_12 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_12)
	    {
	      pt_Progression_12->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_12 = kTRUE;
	    }

	  TString Result_Progression_13 = "LUT_Progression_13";
	  Int_t IsoCut_Progression_13 = histosIsolation[Result_Progression_13]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_13 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_13)
	    {
	      pt_Progression_13->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_13 = kTRUE;
	    }

	  TString Result_Progression_14 = "LUT_Progression_14";
	  Int_t IsoCut_Progression_14 = histosIsolation[Result_Progression_14]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_14 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_14)
	    {
	      pt_Progression_14->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_14 = kTRUE;
	    }

	  TString Result_Progression_15 = "LUT_Progression_15";
	  Int_t IsoCut_Progression_15 = histosIsolation[Result_Progression_15]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_15 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_15)
	    {
	      pt_Progression_15->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_15 = kTRUE;
	    }

	  TString Result_Progression_16 = "LUT_Progression_16";
	  Int_t IsoCut_Progression_16 = histosIsolation[Result_Progression_16]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_16 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_16)
	    {
	      pt_Progression_16->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_16 = kTRUE;
	    }

	  TString Result_Progression_17 = "LUT_Progression_17";
	  Int_t IsoCut_Progression_17 = histosIsolation[Result_Progression_17]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_17 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_17)
	    {
	      pt_Progression_17->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_17 = kTRUE;
	    }

	  TString Result_Progression_18 = "LUT_Progression_18";
	  Int_t IsoCut_Progression_18 = histosIsolation[Result_Progression_18]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_18 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_18)
	    {
	      pt_Progression_18->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_18 = kTRUE;
	    }

	  TString Result_Progression_19 = "LUT_Progression_19";
	  Int_t IsoCut_Progression_19 = histosIsolation[Result_Progression_19]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_19 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_19)
	    {
	      pt_Progression_19->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_19 = kTRUE;
	    }

	  TString Result_Progression_20 = "LUT_Progression_20";
	  Int_t IsoCut_Progression_20 = histosIsolation[Result_Progression_20]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_20 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_20)
	    {
	      pt_Progression_20->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_20 = kTRUE;
	    }

	  TString Result_Progression_21 = "LUT_Progression_21";
	  Int_t IsoCut_Progression_21 = histosIsolation[Result_Progression_21]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_21 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_21)
	    {
	      pt_Progression_21->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_21 = kTRUE;
	    }

	  TString Result_Progression_22 = "LUT_Progression_22";
	  Int_t IsoCut_Progression_22 = histosIsolation[Result_Progression_22]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  if(!Filled_Progression_22 && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_22)
	    {
	      pt_Progression_22->Fill(in_CalibPt->at(iL1Tau));
	      Filled_Progression_22 = kTRUE;
	    }
	  /*
	  TString Result_Progression_31_extrap = "LUT_Progression_31_extrap";
          Int_t IsoCut_Progression_31_extrap = histosIsolation[Result_Progression_31_extrap]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
          if(!Filled_Progression_31_extrap && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_31_extrap)
            {
              pt_Progression_31_extrap->Fill(in_CalibPt->at(iL1Tau));
              Filled_Progression_31_extrap = kTRUE;
            }
	  */

	  //DiTau trigger
	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_IsoInf.at(0))
	    {
	      Index_Taus_IsoInf.at(1)=Index_Taus_IsoInf.at(0);
	      pt_Taus_IsoInf.at(1)=pt_Taus_IsoInf.at(0);
	      Index_Taus_IsoInf.at(0)=iL1Tau;
	      pt_Taus_IsoInf.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_IsoInf.at(1))
	    {
	      Index_Taus_IsoInf.at(1)=iL1Tau;
	      pt_Taus_IsoInf.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_1.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_1)
	    {
	      Index_Taus_Progression_1.at(1)=Index_Taus_Progression_1.at(0);
	      pt_Taus_Progression_1.at(1)=pt_Taus_Progression_1.at(0);
	      Index_Taus_Progression_1.at(0)=iL1Tau;
	      pt_Taus_Progression_1.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_1.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_1)
	    {
	      Index_Taus_Progression_1.at(1)=iL1Tau;
	      pt_Taus_Progression_1.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_2.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_2)
	    {
	      Index_Taus_Progression_2.at(1)=Index_Taus_Progression_2.at(0);
	      pt_Taus_Progression_2.at(1)=pt_Taus_Progression_2.at(0);
	      Index_Taus_Progression_2.at(0)=iL1Tau;
	      pt_Taus_Progression_2.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_2.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_2)
	    {
	      Index_Taus_Progression_2.at(1)=iL1Tau;
	      pt_Taus_Progression_2.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_3.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_3)
	    {
	      Index_Taus_Progression_3.at(1)=Index_Taus_Progression_3.at(0);
	      pt_Taus_Progression_3.at(1)=pt_Taus_Progression_3.at(0);
	      Index_Taus_Progression_3.at(0)=iL1Tau;
	      pt_Taus_Progression_3.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_3.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_3)
	    {
	      Index_Taus_Progression_3.at(1)=iL1Tau;
	      pt_Taus_Progression_3.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_4.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_4)
	    {
	      Index_Taus_Progression_4.at(1)=Index_Taus_Progression_4.at(0);
	      pt_Taus_Progression_4.at(1)=pt_Taus_Progression_4.at(0);
	      Index_Taus_Progression_4.at(0)=iL1Tau;
	      pt_Taus_Progression_4.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_4.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_4)
	    {
	      Index_Taus_Progression_4.at(1)=iL1Tau;
	      pt_Taus_Progression_4.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_5.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_5)
	    {
	      Index_Taus_Progression_5.at(1)=Index_Taus_Progression_5.at(0);
	      pt_Taus_Progression_5.at(1)=pt_Taus_Progression_5.at(0);
	      Index_Taus_Progression_5.at(0)=iL1Tau;
	      pt_Taus_Progression_5.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_5.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_5)
	    {
	      Index_Taus_Progression_5.at(1)=iL1Tau;
	      pt_Taus_Progression_5.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_6.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_6)
	    {
	      Index_Taus_Progression_6.at(1)=Index_Taus_Progression_6.at(0);
	      pt_Taus_Progression_6.at(1)=pt_Taus_Progression_6.at(0);
	      Index_Taus_Progression_6.at(0)=iL1Tau;
	      pt_Taus_Progression_6.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_6.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_6)
	    {
	      Index_Taus_Progression_6.at(1)=iL1Tau;
	      pt_Taus_Progression_6.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_7.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_7)
	    {
	      Index_Taus_Progression_7.at(1)=Index_Taus_Progression_7.at(0);
	      pt_Taus_Progression_7.at(1)=pt_Taus_Progression_7.at(0);
	      Index_Taus_Progression_7.at(0)=iL1Tau;
	      pt_Taus_Progression_7.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_7.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_7)
	    {
	      Index_Taus_Progression_7.at(1)=iL1Tau;
	      pt_Taus_Progression_7.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_8.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_8)
	    {
	      Index_Taus_Progression_8.at(1)=Index_Taus_Progression_8.at(0);
	      pt_Taus_Progression_8.at(1)=pt_Taus_Progression_8.at(0);
	      Index_Taus_Progression_8.at(0)=iL1Tau;
	      pt_Taus_Progression_8.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_8.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_8)
	    {
	      Index_Taus_Progression_8.at(1)=iL1Tau;
	      pt_Taus_Progression_8.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_9.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_9)
	    {
	      Index_Taus_Progression_9.at(1)=Index_Taus_Progression_9.at(0);
	      pt_Taus_Progression_9.at(1)=pt_Taus_Progression_9.at(0);
	      Index_Taus_Progression_9.at(0)=iL1Tau;
	      pt_Taus_Progression_9.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_9.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_9)
	    {
	      Index_Taus_Progression_9.at(1)=iL1Tau;
	      pt_Taus_Progression_9.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_10.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_10)
	    {
	      Index_Taus_Progression_10.at(1)=Index_Taus_Progression_10.at(0);
	      pt_Taus_Progression_10.at(1)=pt_Taus_Progression_10.at(0);
	      Index_Taus_Progression_10.at(0)=iL1Tau;
	      pt_Taus_Progression_10.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_10.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_10)
	    {
	      Index_Taus_Progression_10.at(1)=iL1Tau;
	      pt_Taus_Progression_10.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_11.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_11)
	    {
	      Index_Taus_Progression_11.at(1)=Index_Taus_Progression_11.at(0);
	      pt_Taus_Progression_11.at(1)=pt_Taus_Progression_11.at(0);
	      Index_Taus_Progression_11.at(0)=iL1Tau;
	      pt_Taus_Progression_11.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_11.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_11)
	    {
	      Index_Taus_Progression_11.at(1)=iL1Tau;
	      pt_Taus_Progression_11.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_12.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_12)
	    {
	      Index_Taus_Progression_12.at(1)=Index_Taus_Progression_12.at(0);
	      pt_Taus_Progression_12.at(1)=pt_Taus_Progression_12.at(0);
	      Index_Taus_Progression_12.at(0)=iL1Tau;
	      pt_Taus_Progression_12.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_12.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_12)
	    {
	      Index_Taus_Progression_12.at(1)=iL1Tau;
	      pt_Taus_Progression_12.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_13.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_13)
	    {
	      Index_Taus_Progression_13.at(1)=Index_Taus_Progression_13.at(0);
	      pt_Taus_Progression_13.at(1)=pt_Taus_Progression_13.at(0);
	      Index_Taus_Progression_13.at(0)=iL1Tau;
	      pt_Taus_Progression_13.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_13.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_13)
	    {
	      Index_Taus_Progression_13.at(1)=iL1Tau;
	      pt_Taus_Progression_13.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_14.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_14)
	    {
	      Index_Taus_Progression_14.at(1)=Index_Taus_Progression_14.at(0);
	      pt_Taus_Progression_14.at(1)=pt_Taus_Progression_14.at(0);
	      Index_Taus_Progression_14.at(0)=iL1Tau;
	      pt_Taus_Progression_14.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_14.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_14)
	    {
	      Index_Taus_Progression_14.at(1)=iL1Tau;
	      pt_Taus_Progression_14.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_15.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_15)
	    {
	      Index_Taus_Progression_15.at(1)=Index_Taus_Progression_15.at(0);
	      pt_Taus_Progression_15.at(1)=pt_Taus_Progression_15.at(0);
	      Index_Taus_Progression_15.at(0)=iL1Tau;
	      pt_Taus_Progression_15.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_15.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_15)
	    {
	      Index_Taus_Progression_15.at(1)=iL1Tau;
	      pt_Taus_Progression_15.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_16.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_16)
	    {
	      Index_Taus_Progression_16.at(1)=Index_Taus_Progression_16.at(0);
	      pt_Taus_Progression_16.at(1)=pt_Taus_Progression_16.at(0);
	      Index_Taus_Progression_16.at(0)=iL1Tau;
	      pt_Taus_Progression_16.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_16.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_16)
	    {
	      Index_Taus_Progression_16.at(1)=iL1Tau;
	      pt_Taus_Progression_16.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_17.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_17)
	    {
	      Index_Taus_Progression_17.at(1)=Index_Taus_Progression_17.at(0);
	      pt_Taus_Progression_17.at(1)=pt_Taus_Progression_17.at(0);
	      Index_Taus_Progression_17.at(0)=iL1Tau;
	      pt_Taus_Progression_17.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_17.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_17)
	    {
	      Index_Taus_Progression_17.at(1)=iL1Tau;
	      pt_Taus_Progression_17.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_18.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_18)
	    {
	      Index_Taus_Progression_18.at(1)=Index_Taus_Progression_18.at(0);
	      pt_Taus_Progression_18.at(1)=pt_Taus_Progression_18.at(0);
	      Index_Taus_Progression_18.at(0)=iL1Tau;
	      pt_Taus_Progression_18.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_18.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_18)
	    {
	      Index_Taus_Progression_18.at(1)=iL1Tau;
	      pt_Taus_Progression_18.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_19.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_19)
	    {
	      Index_Taus_Progression_19.at(1)=Index_Taus_Progression_19.at(0);
	      pt_Taus_Progression_19.at(1)=pt_Taus_Progression_19.at(0);
	      Index_Taus_Progression_19.at(0)=iL1Tau;
	      pt_Taus_Progression_19.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_19.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_19)
	    {
	      Index_Taus_Progression_19.at(1)=iL1Tau;
	      pt_Taus_Progression_19.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_20.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_20)
	    {
	      Index_Taus_Progression_20.at(1)=Index_Taus_Progression_20.at(0);
	      pt_Taus_Progression_20.at(1)=pt_Taus_Progression_20.at(0);
	      Index_Taus_Progression_20.at(0)=iL1Tau;
	      pt_Taus_Progression_20.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_20.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_20)
	    {
	      Index_Taus_Progression_20.at(1)=iL1Tau;
	      pt_Taus_Progression_20.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_21.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_21)
	    {
	      Index_Taus_Progression_21.at(1)=Index_Taus_Progression_21.at(0);
	      pt_Taus_Progression_21.at(1)=pt_Taus_Progression_21.at(0);
	      Index_Taus_Progression_21.at(0)=iL1Tau;
	      pt_Taus_Progression_21.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_21.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_21)
	    {
	      Index_Taus_Progression_21.at(1)=iL1Tau;
	      pt_Taus_Progression_21.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_22.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_22)
	    {
	      Index_Taus_Progression_22.at(1)=Index_Taus_Progression_22.at(0);
	      pt_Taus_Progression_22.at(1)=pt_Taus_Progression_22.at(0);
	      eta_Taus_Progression_22.at(1)=eta_Taus_Progression_22.at(0);
	      isMerged_Taus_Progression_22.at(1)=isMerged_Taus_Progression_22.at(0);
	      Index_Taus_Progression_22.at(0)=iL1Tau;
	      pt_Taus_Progression_22.at(0)=in_CalibPt->at(iL1Tau);
	      eta_Taus_Progression_22.at(0)=in_l1tEmuEta->at(iL1Tau);
	      isMerged_Taus_Progression_22.at(0)=in_l1tEmuIsMerged->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_22.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_22)
	    {
	      Index_Taus_Progression_22.at(1)=iL1Tau;
	      pt_Taus_Progression_22.at(1)=in_CalibPt->at(iL1Tau);
	      eta_Taus_Progression_22.at(1)=in_l1tEmuEta->at(iL1Tau);
	      isMerged_Taus_Progression_22.at(1)=in_l1tEmuIsMerged->at(iL1Tau);
	    }
	  /*
	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_31_extrap.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_31_extrap)
            {
              Index_Taus_Progression_31_extrap.at(1)=Index_Taus_Progression_31_extrap.at(0);
              pt_Taus_Progression_31_extrap.at(1)=pt_Taus_Progression_31_extrap.at(0);
              eta_Taus_Progression_31_extrap.at(1)=eta_Taus_Progression_31_extrap.at(0);
              isMerged_Taus_Progression_31_extrap.at(1)=isMerged_Taus_Progression_31_extrap.at(0);
              Index_Taus_Progression_31_extrap.at(0)=iL1Tau;
              pt_Taus_Progression_31_extrap.at(0)=in_CalibPt->at(iL1Tau);
              eta_Taus_Progression_31_extrap.at(0)=in_l1tEmuEta->at(iL1Tau);
              isMerged_Taus_Progression_31_extrap.at(0)=in_l1tEmuIsMerged->at(iL1Tau);
            }
          else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_31_extrap.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_31_extrap)
            {
              Index_Taus_Progression_31_extrap.at(1)=iL1Tau;
              pt_Taus_Progression_31_extrap.at(1)=in_CalibPt->at(iL1Tau);
              eta_Taus_Progression_31_extrap.at(1)=in_l1tEmuEta->at(iL1Tau);
              isMerged_Taus_Progression_31_extrap.at(1)=in_l1tEmuIsMerged->at(iL1Tau);
            }
	  */



	}
      
      Bool_t Flag1 = false;
      Bool_t Flag2 = false;

      if(Index_Taus_IsoInf.at(0)>=0 && Index_Taus_IsoInf.at(1)>=0)
	{
	  pt_IsoInf_DiTau->Fill(pt_Taus_IsoInf.at(0),pt_Taus_IsoInf.at(1),weight);
	  if(pt_Taus_IsoInf.at(0)>80. && pt_Taus_IsoInf.at(1)>80.)
	    {
	      Flag1 = true;
	      DiTauCounterAll++;
	      // cout<<"event passing no iso"<<endl;
	    }
	}

      if(Index_Taus_Progression_1.at(0)>=0 && Index_Taus_Progression_1.at(1)>=0)
	{
	  pt_DiTau_Progression_1->Fill(pt_Taus_Progression_1.at(0),pt_Taus_Progression_1.at(1),weight);
	}
      if(Index_Taus_Progression_2.at(0)>=0 && Index_Taus_Progression_2.at(1)>=0)
	{
	  pt_DiTau_Progression_2->Fill(pt_Taus_Progression_2.at(0),pt_Taus_Progression_2.at(1),weight);
	}
      if(Index_Taus_Progression_3.at(0)>=0 && Index_Taus_Progression_3.at(1)>=0)
	{
	  pt_DiTau_Progression_3->Fill(pt_Taus_Progression_3.at(0),pt_Taus_Progression_3.at(1),weight);
	}
      if(Index_Taus_Progression_4.at(0)>=0 && Index_Taus_Progression_4.at(1)>=0)
	{
	  pt_DiTau_Progression_4->Fill(pt_Taus_Progression_4.at(0),pt_Taus_Progression_4.at(1),weight);
	}
      if(Index_Taus_Progression_5.at(0)>=0 && Index_Taus_Progression_5.at(1)>=0)
	{
	  pt_DiTau_Progression_5->Fill(pt_Taus_Progression_5.at(0),pt_Taus_Progression_5.at(1),weight);
	}
      if(Index_Taus_Progression_6.at(0)>=0 && Index_Taus_Progression_6.at(1)>=0)
	{
	  pt_DiTau_Progression_6->Fill(pt_Taus_Progression_6.at(0),pt_Taus_Progression_6.at(1),weight);
	}
      if(Index_Taus_Progression_7.at(0)>=0 && Index_Taus_Progression_7.at(1)>=0)
	{
	  pt_DiTau_Progression_7->Fill(pt_Taus_Progression_7.at(0),pt_Taus_Progression_7.at(1),weight);
	}
      if(Index_Taus_Progression_8.at(0)>=0 && Index_Taus_Progression_8.at(1)>=0)
	{
	  pt_DiTau_Progression_8->Fill(pt_Taus_Progression_8.at(0),pt_Taus_Progression_8.at(1),weight);
	}
      if(Index_Taus_Progression_9.at(0)>=0 && Index_Taus_Progression_9.at(1)>=0)
	{
	  pt_DiTau_Progression_9->Fill(pt_Taus_Progression_9.at(0),pt_Taus_Progression_9.at(1),weight);
	}
      if(Index_Taus_Progression_10.at(0)>=0 && Index_Taus_Progression_10.at(1)>=0)
	{
	  pt_DiTau_Progression_10->Fill(pt_Taus_Progression_10.at(0),pt_Taus_Progression_10.at(1),weight);
	}
      if(Index_Taus_Progression_11.at(0)>=0 && Index_Taus_Progression_11.at(1)>=0)
	{
	  pt_DiTau_Progression_11->Fill(pt_Taus_Progression_11.at(0),pt_Taus_Progression_11.at(1),weight);
	}
      if(Index_Taus_Progression_12.at(0)>=0 && Index_Taus_Progression_12.at(1)>=0)
	{
	  pt_DiTau_Progression_12->Fill(pt_Taus_Progression_12.at(0),pt_Taus_Progression_12.at(1),weight);
	}
      if(Index_Taus_Progression_13.at(0)>=0 && Index_Taus_Progression_13.at(1)>=0)
	{
	  pt_DiTau_Progression_13->Fill(pt_Taus_Progression_13.at(0),pt_Taus_Progression_13.at(1),weight);
	}
      if(Index_Taus_Progression_14.at(0)>=0 && Index_Taus_Progression_14.at(1)>=0)
	{
	  pt_DiTau_Progression_14->Fill(pt_Taus_Progression_14.at(0),pt_Taus_Progression_14.at(1),weight);
	}
      if(Index_Taus_Progression_15.at(0)>=0 && Index_Taus_Progression_15.at(1)>=0)
	{
	  pt_DiTau_Progression_15->Fill(pt_Taus_Progression_15.at(0),pt_Taus_Progression_15.at(1),weight);
	}
      if(Index_Taus_Progression_16.at(0)>=0 && Index_Taus_Progression_16.at(1)>=0)
	{
	  pt_DiTau_Progression_16->Fill(pt_Taus_Progression_16.at(0),pt_Taus_Progression_16.at(1),weight);
	}
      if(Index_Taus_Progression_17.at(0)>=0 && Index_Taus_Progression_17.at(1)>=0)
	{
	  pt_DiTau_Progression_17->Fill(pt_Taus_Progression_17.at(0),pt_Taus_Progression_17.at(1),weight);
	}
      if(Index_Taus_Progression_18.at(0)>=0 && Index_Taus_Progression_18.at(1)>=0)
	{
	  pt_DiTau_Progression_18->Fill(pt_Taus_Progression_18.at(0),pt_Taus_Progression_18.at(1),weight);
	}
      if(Index_Taus_Progression_19.at(0)>=0 && Index_Taus_Progression_19.at(1)>=0)
	{
	  pt_DiTau_Progression_19->Fill(pt_Taus_Progression_19.at(0),pt_Taus_Progression_19.at(1),weight);
	}
      if(Index_Taus_Progression_20.at(0)>=0 && Index_Taus_Progression_20.at(1)>=0)
	{
	  pt_DiTau_Progression_20->Fill(pt_Taus_Progression_20.at(0),pt_Taus_Progression_20.at(1),weight);
	}
      if(Index_Taus_Progression_21.at(0)>=0 && Index_Taus_Progression_21.at(1)>=0)
	{
	  pt_DiTau_Progression_21->Fill(pt_Taus_Progression_21.at(0),pt_Taus_Progression_21.at(1),weight);
	}
      if(Index_Taus_Progression_22.at(0)>=0 && Index_Taus_Progression_22.at(1)>=0)
	{
	  pt_DiTau_Progression_22->Fill(pt_Taus_Progression_22.at(0),pt_Taus_Progression_22.at(1),weight);
	}
      if(Index_Taus_Progression_31_extrap.at(0)>=0 && Index_Taus_Progression_31_extrap.at(1)>=0)
        {
          pt_DiTau_Progression_31_extrap->Fill(pt_Taus_Progression_31_extrap.at(0),pt_Taus_Progression_31_extrap.at(1),weight);
        }

    }

  cout<<"CounterAll = "<<CounterAll<<endl;
  cout<<"CounterPass = "<<CounterPass<<endl;
  cout<<"CounterFail = "<<CounterFail<<endl;

  cout<<"DiTauCounterAll = "<<DiTauCounterAll<<endl;
  cout<<"DiTauCounterPass = "<<DiTauCounterPass<<endl;

  //for run 315512
  float nb = 1874.;
  float thisLumiRun = 1.1837E34;

  //float nb = 1866.;
  //float thisLumiRun = 1.46E34;
  float scaleToLumi = 2.00E34;
  //float scale = 0.001*(nb*11245.6)*scaleToLumi/thisLumiRun;
  float scale = 28.0E6 / 1000; // for MC to make scale in kHz 
  /*
    For MC
    rate = (crossSection * iLumi) * (count / events)
    iLumi = 7.5E34 / cm^2 / s
    For Data
    rate = (numbebOfBranch * frequncy) * (count / events)
    (numbebOfBranch * frequncy) is scaled with luminosity (scaleToLumi/thisLumiRun)
   */
  cout<<"Denominator = "<<Denominator<<endl;

  TH1F* rate_Stage1 = new TH1F("rate_Stage1","rate_Stage1",240,0.,240.);
  TH1F* rate_Progression_1 = new TH1F("rate_Progression_1","rate_Progression_1",240,0.,240.);
  TH1F* rate_Progression_2 = new TH1F("rate_Progression_2","rate_Progression_2",240,0.,240.);
  TH1F* rate_Progression_3 = new TH1F("rate_Progression_3","rate_Progression_3",240,0.,240.);
  TH1F* rate_Progression_4 = new TH1F("rate_Progression_4","rate_Progression_4",240,0.,240.);
  TH1F* rate_Progression_5 = new TH1F("rate_Progression_5","rate_Progression_5",240,0.,240.);
  TH1F* rate_Progression_6 = new TH1F("rate_Progression_6","rate_Progression_6",240,0.,240.);
  TH1F* rate_Progression_7 = new TH1F("rate_Progression_7","rate_Progression_7",240,0.,240.);
  TH1F* rate_Progression_8 = new TH1F("rate_Progression_8","rate_Progression_8",240,0.,240.);
  TH1F* rate_Progression_9 = new TH1F("rate_Progression_9","rate_Progression_9",240,0.,240.);
  TH1F* rate_Progression_10 = new TH1F("rate_Progression_10","rate_Progression_10",240,0.,240.);
  TH1F* rate_Progression_11 = new TH1F("rate_Progression_11","rate_Progression_11",240,0.,240.);
  TH1F* rate_Progression_12 = new TH1F("rate_Progression_12","rate_Progression_12",240,0.,240.);
  TH1F* rate_Progression_13 = new TH1F("rate_Progression_13","rate_Progression_13",240,0.,240.);
  TH1F* rate_Progression_14 = new TH1F("rate_Progression_14","rate_Progression_14",240,0.,240.);
  TH1F* rate_Progression_15 = new TH1F("rate_Progression_15","rate_Progression_15",240,0.,240.);
  TH1F* rate_Progression_16 = new TH1F("rate_Progression_16","rate_Progression_16",240,0.,240.);
  TH1F* rate_Progression_17 = new TH1F("rate_Progression_17","rate_Progression_17",240,0.,240.);
  TH1F* rate_Progression_18 = new TH1F("rate_Progression_18","rate_Progression_18",240,0.,240.);
  TH1F* rate_Progression_19 = new TH1F("rate_Progression_19","rate_Progression_19",240,0.,240.);
  TH1F* rate_Progression_20 = new TH1F("rate_Progression_20","rate_Progression_20",240,0.,240.);
  TH1F* rate_Progression_21 = new TH1F("rate_Progression_21","rate_Progression_21",240,0.,240.);
  TH1F* rate_Progression_22 = new TH1F("rate_Progression_22","rate_Progression_22",240,0.,240.);
  TH1F* rate_Progression_31_extrap = new TH1F("rate_Progression_31_extrap","rate_Progression_31_extrap",240,0.,240.);


  TH1F* rate_noCut_DiTau = new TH1F("rate_noCut_DiTau","rate_noCut_DiTau",240,0.,240.);
  TH1F* rate_DiTau_Progression_1 = new TH1F("rate_DiTau_Progression_1","rate_DiTau_Progression_1",240,0.,240.);
  TH1F* rate_DiTau_Progression_2 = new TH1F("rate_DiTau_Progression_2","rate_DiTau_Progression_2",240,0.,240.);
  TH1F* rate_DiTau_Progression_3 = new TH1F("rate_DiTau_Progression_3","rate_DiTau_Progression_3",240,0.,240.);
  TH1F* rate_DiTau_Progression_4 = new TH1F("rate_DiTau_Progression_4","rate_DiTau_Progression_4",240,0.,240.);
  TH1F* rate_DiTau_Progression_5 = new TH1F("rate_DiTau_Progression_5","rate_DiTau_Progression_5",240,0.,240.);
  TH1F* rate_DiTau_Progression_6 = new TH1F("rate_DiTau_Progression_6","rate_DiTau_Progression_6",240,0.,240.);
  TH1F* rate_DiTau_Progression_7 = new TH1F("rate_DiTau_Progression_7","rate_DiTau_Progression_7",240,0.,240.);
  TH1F* rate_DiTau_Progression_8 = new TH1F("rate_DiTau_Progression_8","rate_DiTau_Progression_8",240,0.,240.);
  TH1F* rate_DiTau_Progression_9 = new TH1F("rate_DiTau_Progression_9","rate_DiTau_Progression_9",240,0.,240.);
  TH1F* rate_DiTau_Progression_10 = new TH1F("rate_DiTau_Progression_10","rate_DiTau_Progression_10",240,0.,240.);
  TH1F* rate_DiTau_Progression_11 = new TH1F("rate_DiTau_Progression_11","rate_DiTau_Progression_11",240,0.,240.);
  TH1F* rate_DiTau_Progression_12 = new TH1F("rate_DiTau_Progression_12","rate_DiTau_Progression_12",240,0.,240.);
  TH1F* rate_DiTau_Progression_13 = new TH1F("rate_DiTau_Progression_13","rate_DiTau_Progression_13",240,0.,240.);
  TH1F* rate_DiTau_Progression_14 = new TH1F("rate_DiTau_Progression_14","rate_DiTau_Progression_14",240,0.,240.);
  TH1F* rate_DiTau_Progression_15 = new TH1F("rate_DiTau_Progression_15","rate_DiTau_Progression_15",240,0.,240.);
  TH1F* rate_DiTau_Progression_16 = new TH1F("rate_DiTau_Progression_16","rate_DiTau_Progression_16",240,0.,240.);
  TH1F* rate_DiTau_Progression_17 = new TH1F("rate_DiTau_Progression_17","rate_DiTau_Progression_17",240,0.,240.);
  TH1F* rate_DiTau_Progression_18 = new TH1F("rate_DiTau_Progression_18","rate_DiTau_Progression_18",240,0.,240.);
  TH1F* rate_DiTau_Progression_19 = new TH1F("rate_DiTau_Progression_19","rate_DiTau_Progression_19",240,0.,240.);
  TH1F* rate_DiTau_Progression_20 = new TH1F("rate_DiTau_Progression_20","rate_DiTau_Progression_20",240,0.,240.);
  TH1F* rate_DiTau_Progression_21 = new TH1F("rate_DiTau_Progression_21","rate_DiTau_Progression_21",240,0.,240.);
  TH1F* rate_DiTau_Progression_22 = new TH1F("rate_DiTau_Progression_22","rate_DiTau_Progression_22",240,0.,240.);
  TH1F* rate_DiTau_Progression_31_extrap = new TH1F("rate_DiTau_Progression_31_extrap","rate_DiTau_Progression_31_extrap",240,0.,240.);

  for(UInt_t i = 0 ; i < 241 ; ++i)
    {
      rate_Progression_1->SetBinContent(i+1,pt_Progression_1->Integral(i+1,241)/Denominator*scale);
      rate_Progression_2->SetBinContent(i+1,pt_Progression_2->Integral(i+1,241)/Denominator*scale);
      rate_Progression_3->SetBinContent(i+1,pt_Progression_3->Integral(i+1,241)/Denominator*scale);
      rate_Progression_4->SetBinContent(i+1,pt_Progression_4->Integral(i+1,241)/Denominator*scale);
      rate_Progression_5->SetBinContent(i+1,pt_Progression_5->Integral(i+1,241)/Denominator*scale);
      rate_Progression_6->SetBinContent(i+1,pt_Progression_6->Integral(i+1,241)/Denominator*scale);
      rate_Progression_7->SetBinContent(i+1,pt_Progression_7->Integral(i+1,241)/Denominator*scale);
      rate_Progression_8->SetBinContent(i+1,pt_Progression_8->Integral(i+1,241)/Denominator*scale);
      rate_Progression_9->SetBinContent(i+1,pt_Progression_9->Integral(i+1,241)/Denominator*scale);
      rate_Progression_10->SetBinContent(i+1,pt_Progression_10->Integral(i+1,241)/Denominator*scale);
      rate_Progression_11->SetBinContent(i+1,pt_Progression_11->Integral(i+1,241)/Denominator*scale);
      rate_Progression_12->SetBinContent(i+1,pt_Progression_12->Integral(i+1,241)/Denominator*scale);
      rate_Progression_13->SetBinContent(i+1,pt_Progression_13->Integral(i+1,241)/Denominator*scale);
      rate_Progression_14->SetBinContent(i+1,pt_Progression_14->Integral(i+1,241)/Denominator*scale);
      rate_Progression_15->SetBinContent(i+1,pt_Progression_15->Integral(i+1,241)/Denominator*scale);
      rate_Progression_16->SetBinContent(i+1,pt_Progression_16->Integral(i+1,241)/Denominator*scale);
      rate_Progression_17->SetBinContent(i+1,pt_Progression_17->Integral(i+1,241)/Denominator*scale);
      rate_Progression_18->SetBinContent(i+1,pt_Progression_18->Integral(i+1,241)/Denominator*scale);
      rate_Progression_19->SetBinContent(i+1,pt_Progression_19->Integral(i+1,241)/Denominator*scale);
      rate_Progression_20->SetBinContent(i+1,pt_Progression_20->Integral(i+1,241)/Denominator*scale);
      rate_Progression_21->SetBinContent(i+1,pt_Progression_21->Integral(i+1,241)/Denominator*scale);
      rate_Progression_22->SetBinContent(i+1,pt_Progression_22->Integral(i+1,241)/Denominator*scale);
      rate_Progression_31_extrap->SetBinContent(i+1,pt_Progression_31_extrap->Integral(i+1,241)/Denominator*scale);


      rate_noCut_DiTau->SetBinContent(i+1,pt_IsoInf_DiTau->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_1->SetBinContent(i+1,pt_DiTau_Progression_1->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_2->SetBinContent(i+1,pt_DiTau_Progression_2->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_3->SetBinContent(i+1,pt_DiTau_Progression_3->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_4->SetBinContent(i+1,pt_DiTau_Progression_4->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_5->SetBinContent(i+1,pt_DiTau_Progression_5->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_6->SetBinContent(i+1,pt_DiTau_Progression_6->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_7->SetBinContent(i+1,pt_DiTau_Progression_7->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_8->SetBinContent(i+1,pt_DiTau_Progression_8->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_9->SetBinContent(i+1,pt_DiTau_Progression_9->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_10->SetBinContent(i+1,pt_DiTau_Progression_10->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_11->SetBinContent(i+1,pt_DiTau_Progression_11->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_12->SetBinContent(i+1,pt_DiTau_Progression_12->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_13->SetBinContent(i+1,pt_DiTau_Progression_13->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_14->SetBinContent(i+1,pt_DiTau_Progression_14->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_15->SetBinContent(i+1,pt_DiTau_Progression_15->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_16->SetBinContent(i+1,pt_DiTau_Progression_16->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_17->SetBinContent(i+1,pt_DiTau_Progression_17->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_18->SetBinContent(i+1,pt_DiTau_Progression_18->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_19->SetBinContent(i+1,pt_DiTau_Progression_19->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_20->SetBinContent(i+1,pt_DiTau_Progression_20->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_21->SetBinContent(i+1,pt_DiTau_Progression_21->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_22->SetBinContent(i+1,pt_DiTau_Progression_22->Integral(i+1,241,i+1,241)/Denominator*scale);
      rate_DiTau_Progression_31_extrap->SetBinContent(i+1,pt_DiTau_Progression_31_extrap->Integral(i+1,241,i+1,241)/Denominator*scale);

    }

  pt_Progression_1->Write();
  pt_Progression_2->Write();
  pt_Progression_3->Write();
  pt_Progression_4->Write();
  pt_Progression_5->Write();
  pt_Progression_6->Write();
  pt_Progression_7->Write();
  pt_Progression_8->Write();
  pt_Progression_9->Write();
  pt_Progression_10->Write();
  pt_Progression_11->Write();
  pt_Progression_12->Write();
  pt_Progression_13->Write();
  pt_Progression_14->Write();
  pt_Progression_15->Write();
  pt_Progression_16->Write();
  pt_Progression_17->Write();
  pt_Progression_18->Write();
  pt_Progression_19->Write();
  pt_Progression_20->Write();
  pt_Progression_21->Write();
  pt_Progression_22->Write();
  pt_Progression_31_extrap->Write();

  pt_IsoInf_DiTau->Write();
  pt_DiTau_Progression_1->Write();
  pt_DiTau_Progression_2->Write();
  pt_DiTau_Progression_4->Write();
  pt_DiTau_Progression_5->Write();
  pt_DiTau_Progression_6->Write();
  pt_DiTau_Progression_7->Write();
  pt_DiTau_Progression_8->Write();
  pt_DiTau_Progression_9->Write();
  pt_DiTau_Progression_10->Write();
  pt_DiTau_Progression_11->Write();
  pt_DiTau_Progression_12->Write();
  pt_DiTau_Progression_13->Write();
  pt_DiTau_Progression_14->Write();
  pt_DiTau_Progression_15->Write();
  pt_DiTau_Progression_16->Write();
  pt_DiTau_Progression_17->Write();
  pt_DiTau_Progression_18->Write();
  pt_DiTau_Progression_19->Write();
  pt_DiTau_Progression_20->Write();
  pt_DiTau_Progression_21->Write();
  pt_DiTau_Progression_22->Write();
  pt_DiTau_Progression_31_extrap->Write();

  rate_Progression_1->Write();  
  rate_Progression_2->Write();  
  rate_Progression_3->Write();  
  rate_Progression_4->Write();  
  rate_Progression_5->Write();  
  rate_Progression_6->Write();  
  rate_Progression_7->Write();  
  rate_Progression_8->Write();  
  rate_Progression_9->Write();  
  rate_Progression_10->Write();  
  rate_Progression_11->Write();  
  rate_Progression_12->Write();  
  rate_Progression_13->Write();  
  rate_Progression_14->Write();  
  rate_Progression_15->Write();  
  rate_Progression_16->Write();  
  rate_Progression_17->Write();  
  rate_Progression_18->Write();  
  rate_Progression_19->Write();  
  rate_Progression_20->Write();  
  rate_Progression_21->Write();  
  rate_Progression_22->Write();  
  rate_Progression_31_extrap->Write();

  rate_noCut_DiTau->Write();
  rate_DiTau_Progression_1->Write();
  rate_DiTau_Progression_2->Write();
  rate_DiTau_Progression_3->Write();
  rate_DiTau_Progression_4->Write();
  rate_DiTau_Progression_5->Write();
  rate_DiTau_Progression_6->Write();
  rate_DiTau_Progression_7->Write();
  rate_DiTau_Progression_8->Write();
  rate_DiTau_Progression_9->Write();
  rate_DiTau_Progression_10->Write();
  rate_DiTau_Progression_11->Write();
  rate_DiTau_Progression_12->Write();
  rate_DiTau_Progression_13->Write();
  rate_DiTau_Progression_14->Write();
  rate_DiTau_Progression_15->Write();
  rate_DiTau_Progression_16->Write();
  rate_DiTau_Progression_17->Write();
  rate_DiTau_Progression_18->Write();
  rate_DiTau_Progression_19->Write();
  rate_DiTau_Progression_20->Write();
  rate_DiTau_Progression_21->Write();
  rate_DiTau_Progression_22->Write();
  rate_DiTau_Progression_31_extrap->Write();
  rate_Stage1->Write();  
  return;
}
