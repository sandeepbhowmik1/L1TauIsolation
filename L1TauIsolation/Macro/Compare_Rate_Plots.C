{
  TString fileName_In = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/hist_rate_calibratedOutputZeroBias_MC_SingleNeutrino_Iso_LUT_Option_20210727.root";
  TString fileName_Out = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/plots/plots_Rate_calibratedOutputZeroBias_MC_SingleNeutrino_Iso_LUT_Option_20210727";

  TFile fileIn(fileName_In.Data(),"READ");

  bool Draw_Options = kTRUE;
  gStyle->SetOptStat(000000);
  gStyle->SetOptTitle(0);
  //  gStyle->SetTitle(0);

  TH1F* rate_NewLayer1_noIso   = (TH1F*)fileIn.Get("rate_noCut_DiTau");    
  TH1F* rate_NewLayer1_Option1 = (TH1F*)fileIn.Get("rate_DiTau_Progression_1");
  TH1F* rate_NewLayer1_Option2 = (TH1F*)fileIn.Get("rate_DiTau_Progression_2");
  TH1F* rate_NewLayer1_Option3 = (TH1F*)fileIn.Get("rate_DiTau_Progression_3");
  TH1F* rate_NewLayer1_Option4 = (TH1F*)fileIn.Get("rate_DiTau_Progression_4");
  TH1F* rate_NewLayer1_Option5 = (TH1F*)fileIn.Get("rate_DiTau_Progression_5");
  TH1F* rate_NewLayer1_Option6 = (TH1F*)fileIn.Get("rate_DiTau_Progression_6");
  TH1F* rate_NewLayer1_Option7 = (TH1F*)fileIn.Get("rate_DiTau_Progression_7");
  TH1F* rate_NewLayer1_Option8 = (TH1F*)fileIn.Get("rate_DiTau_Progression_8");
  TH1F* rate_NewLayer1_Option9 = (TH1F*)fileIn.Get("rate_DiTau_Progression_9");
  TH1F* rate_NewLayer1_Option10 = (TH1F*)fileIn.Get("rate_DiTau_Progression_10");
  TH1F* rate_NewLayer1_Option11 = (TH1F*)fileIn.Get("rate_DiTau_Progression_11");
  TH1F* rate_NewLayer1_Option12 = (TH1F*)fileIn.Get("rate_DiTau_Progression_12");
  TH1F* rate_NewLayer1_Option13 = (TH1F*)fileIn.Get("rate_DiTau_Progression_13");
  TH1F* rate_NewLayer1_Option14 = (TH1F*)fileIn.Get("rate_DiTau_Progression_14");
  TH1F* rate_NewLayer1_Option15 = (TH1F*)fileIn.Get("rate_DiTau_Progression_15");
  TH1F* rate_NewLayer1_Option16 = (TH1F*)fileIn.Get("rate_DiTau_Progression_16");
  TH1F* rate_NewLayer1_Option17 = (TH1F*)fileIn.Get("rate_DiTau_Progression_17");
  TH1F* rate_NewLayer1_Option18 = (TH1F*)fileIn.Get("rate_DiTau_Progression_18");
  TH1F* rate_NewLayer1_Option19 = (TH1F*)fileIn.Get("rate_DiTau_Progression_19");
  TH1F* rate_NewLayer1_Option20 = (TH1F*)fileIn.Get("rate_DiTau_Progression_20");
  TH1F* rate_NewLayer1_Option21 = (TH1F*)fileIn.Get("rate_DiTau_Progression_21");
  TH1F* rate_NewLayer1_Option22 = (TH1F*)fileIn.Get("rate_DiTau_Progression_22");
  TH1F* rate_NewLayer1_Option23 = (TH1F*)fileIn.Get("rate_DiTau_Progression_23");
  TH1F* rate_NewLayer1_Option24 = (TH1F*)fileIn.Get("rate_DiTau_Progression_24");
  TH1F* rate_NewLayer1_Option25 = (TH1F*)fileIn.Get("rate_DiTau_Progression_25");
  TH1F* rate_NewLayer1_Option26 = (TH1F*)fileIn.Get("rate_DiTau_Progression_26");
  TH1F* rate_NewLayer1_Option27 = (TH1F*)fileIn.Get("rate_DiTau_Progression_27");
  TH1F* rate_NewLayer1_Option28 = (TH1F*)fileIn.Get("rate_DiTau_Progression_28");
  TH1F* rate_NewLayer1_Option29 = (TH1F*)fileIn.Get("rate_DiTau_Progression_29");
  TH1F* rate_NewLayer1_Option30 = (TH1F*)fileIn.Get("rate_DiTau_Progression_30");
  TH1F* rate_NewLayer1_Option31 = (TH1F*)fileIn.Get("rate_DiTau_Progression_31");
  TH1F* rate_NewLayer1_Option31_extrap = (TH1F*)fileIn.Get("rate_DiTau_Progression_31_extrap");

  TString CanvasName = fileName_Out;
  TString CanvasNamePdf = CanvasName ;
  CanvasNamePdf += ".pdf";
  TString CanvasNamePng = CanvasName ;
  CanvasNamePng += ".png";
  TString CanvasNameRoot = CanvasName ;
  CanvasNameRoot += ".root";

  TCanvas c(CanvasName.Data(),CanvasName.Data(),800,800);
  c.SetLeftMargin(0.15);
  c.SetGrid();
  c.SetLogy();

  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->SetGridy();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  pad1->SetLogy();

  rate_NewLayer1_noIso->SetLineWidth(3);
  //  rate_NewLayer1_noIso->SetLineColor(11);
  rate_NewLayer1_noIso->SetLineColor(1);
  //  rate_NewLayer1_noIso->Draw("same");
  rate_NewLayer1_noIso->GetXaxis()->SetRangeUser(20.,60.);
  rate_NewLayer1_noIso->GetYaxis()->SetTitle("Rate [kHz]");
  rate_NewLayer1_noIso->Draw();

  rate_NewLayer1_Option1->SetLineWidth(3);
  rate_NewLayer1_Option1->SetLineColor(2);
  rate_NewLayer1_Option1->Draw("same");

  rate_NewLayer1_Option15->SetLineWidth(3);
  rate_NewLayer1_Option15->SetLineColor(3);
  rate_NewLayer1_Option15->Draw("same");


  rate_NewLayer1_Option22->SetLineColor(4);
  rate_NewLayer1_Option22->SetLineWidth(3);
  rate_NewLayer1_Option22->Draw("same");

  rate_NewLayer1_Option31->SetLineWidth(3);
  rate_NewLayer1_Option31->SetLineColor(6);
  rate_NewLayer1_Option31->Draw("same");

  rate_NewLayer1_Option31_extrap->SetLineWidth(3);
  rate_NewLayer1_Option31_extrap->SetLineColor(7);
  rate_NewLayer1_Option31_extrap->Draw("same");


  TPaveText* texl = new TPaveText(0.20,0.87,0.90,0.99,"NDC");
  //texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #305310 (PU ~ 57)");
  texl->AddText("#scale[1.5]{CMS} Internal         Run3 Simulation                14 TeV");
  // texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #277069 (2064 bunches), 81<lumi<300");

  texl->SetTextSize(0.04);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* leg = new TLegend(0.5,0.51,0.89,0.81);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  //leg->SetHeader("Linearly scaled to 2.0E34");
  leg->AddEntry(rate_NewLayer1_noIso,"#bf{Di-#tau no-iso}","L");
  leg->AddEntry(rate_NewLayer1_Option1,"#bf{Di-#tau iso (Option 1)}","L");
  leg->AddEntry(rate_NewLayer1_Option15,"#bf{Di-#tau iso (Option 15)}","L");
  leg->AddEntry(rate_NewLayer1_Option22,"#bf{Di-#tau iso (Option 22)}","L");
  leg->AddEntry(rate_NewLayer1_Option31,"#bf{Di-#tau iso (Option 31)}","L");
  leg->AddEntry(rate_NewLayer1_Option31_extrap,"#bf{Di-#tau iso (Option 31_extrap)}","L");

  TLine line(0., 18., 120., 18.);
  line.SetLineColor(kRed);
  line.SetLineWidth(4);
  line.SetLineStyle(2);
  // line.Draw("same");

  leg->Draw("same");

  c.cd();

  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.30);
  // pad2->SetBottomMargin(0.25);//was here

  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad

  TH1F* ratioPlot22 = (TH1F*)rate_NewLayer1_noIso->Clone("ratioPlot");
  ratioPlot22->Divide(rate_NewLayer1_Option22);
  ratioPlot22->SetLineColor(kRed);
  ratioPlot22->Draw();
  
  TH1F* ratioPlot1 = (TH1F*)rate_NewLayer1_noIso->Clone("ratioPlot");
  ratioPlot1->Divide(rate_NewLayer1_Option1);
  ratioPlot1->SetLineColor(kMagenta);
  ratioPlot1->Draw("same");
  
  TH1F* ratioPlot2 = (TH1F*)rate_NewLayer1_noIso->Clone("ratioPlot");
  ratioPlot2->Divide(rate_NewLayer1_Option2);
  ratioPlot2->SetLineColor(kBlue);
  //ratioPlot2->Draw("same");
  
  TH1F* ratioPlot8 = (TH1F*)rate_NewLayer1_noIso->Clone("ratioPlot");
  ratioPlot8->Divide(rate_NewLayer1_Option8);
  ratioPlot8->SetLineColor(kGreen);
  ratioPlot8->Draw("same");

  TH1F* ratioPlot15 = (TH1F*)rate_NewLayer1_noIso->Clone("ratioPlot");
  ratioPlot15->Divide(rate_NewLayer1_Option15);
  ratioPlot15->SetLineColor(kCyan);
  ratioPlot15->Draw("same");
 
  ratioPlot->GetXaxis()->SetLabelSize(0.09);
  ratioPlot->GetYaxis()->SetLabelSize(0.09);

  ratioPlot->GetYaxis()->SetTitleSize(0.09);
  ratioPlot->SetTitle("");
  // ratioPlot->GetXaxis()->SetRangeUser(20.,100.);
  ratioPlot->GetXaxis()->SetRangeUser(20.,60.);
  // ratioPlot->GetXaxis()->SetRangeUser(0.,40.);
  ratioPlot->GetYaxis()->SetRangeUser(0.,22.);
  ratioPlot->GetYaxis()->SetTitle("No-iso/iso(Option)");
  ratioPlot->GetXaxis()->SetTitle("E_{T}^{L1} threshold [GeV]");
  // ratioPlot->GetXaxis()->SetTitleOffset(1.3);
  ratioPlot->GetXaxis()->SetTitleSize(0.11);
  // ratioPlot->GetYaxis()->SetTitle("New/Currently online");
  ratioPlot->GetYaxis()->SetTitleOffset(0.5);

  // TLine line2(20., 1., 100., 1.);
  TLine line2(20., 1., 60., 1.);
  // TLine line2(0., 1., 40., 1.);
  line2.SetLineColor(kGreen);
  line2.SetLineStyle(2);
  line2.Draw("same");

  
  c.SaveAs(CanvasNamePdf.Data());
  c.SaveAs(CanvasNamePng.Data());
  c.SaveAs(CanvasNameRoot.Data());

    //find first threshold giving < 10 kHz.
  //Double_t Target = 14.;
  Double_t Target = 26.; //14.*1.76;
  // Double_t Target = 14.;

  Double_t Threshold_NewLayer1_noIso = 0.;
  Double_t Threshold_NewLayer1_Option1 = 0.;
  Double_t Threshold_NewLayer1_Option2 = 0.;
  Double_t Threshold_NewLayer1_Option3 = 0.;
  Double_t Threshold_NewLayer1_Option4 = 0.;
  Double_t Threshold_NewLayer1_Option5 = 0.;
  Double_t Threshold_NewLayer1_Option6 = 0.;
  Double_t Threshold_NewLayer1_Option7 = 0.;
  Double_t Threshold_NewLayer1_Option8 = 0.;
  Double_t Threshold_NewLayer1_Option9 = 0.;
  Double_t Threshold_NewLayer1_Option10 = 0.;
  Double_t Threshold_NewLayer1_Option11 = 0.;
  Double_t Threshold_NewLayer1_Option12 = 0.;
  Double_t Threshold_NewLayer1_Option13 = 0.;
  Double_t Threshold_NewLayer1_Option14 = 0.;
  Double_t Threshold_NewLayer1_Option15 = 0.;
  Double_t Threshold_NewLayer1_Option16 = 0.;
  Double_t Threshold_NewLayer1_Option17 = 0.;
  Double_t Threshold_NewLayer1_Option18 = 0.;
  Double_t Threshold_NewLayer1_Option19 = 0.;
  Double_t Threshold_NewLayer1_Option20 = 0.;
  Double_t Threshold_NewLayer1_Option21 = 0.;
  Double_t Threshold_NewLayer1_Option22 = 0.;
  Double_t Threshold_NewLayer1_Option23 = 0.;
  Double_t Threshold_NewLayer1_Option24 = 0.;
  Double_t Threshold_NewLayer1_Option25 = 0.;
  Double_t Threshold_NewLayer1_Option26 = 0.;
  Double_t Threshold_NewLayer1_Option27 = 0.;
  Double_t Threshold_NewLayer1_Option28 = 0.;
  Double_t Threshold_NewLayer1_Option29 = 0.;
  Double_t Threshold_NewLayer1_Option30 = 0.;
  Double_t Threshold_NewLayer1_Option31 = 0.;
  Double_t Threshold_NewLayer1_Option31_extrap = 0.;
   
  for(UInt_t i = 1 ; i <= rate_NewLayer1_noIso->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_noIso->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_noIso = rate_NewLayer1_noIso->GetBinLowEdge(i);
  	  break;
  	}
    }
  cout<<"rate_NewLayer1_noIso->GetNbinsX() "<<rate_NewLayer1_noIso->GetNbinsX()<<"rate_NewLayer1_noIso->GetBinContent(i) "<<rate_NewLayer1_noIso->GetBinContent(10)<<endl;
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option1->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option1->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option1 = rate_NewLayer1_Option1->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option2->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option2->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option2 = rate_NewLayer1_Option2->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option3->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option3->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option3 = rate_NewLayer1_Option3->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option4->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option4->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option4 = rate_NewLayer1_Option4->GetBinLowEdge(i);
  	  break;
  	}
    }
    
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option5->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option5->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option5 = rate_NewLayer1_Option5->GetBinLowEdge(i);
  	  break;
  	}
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option6->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option6->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option6 = rate_NewLayer1_Option6->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option7->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option7->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option7 = rate_NewLayer1_Option7->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option8->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option8->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option8 = rate_NewLayer1_Option8->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option9->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option9->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option9 = rate_NewLayer1_Option9->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option10->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option10->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option10 = rate_NewLayer1_Option10->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option11->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option11->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option11 = rate_NewLayer1_Option11->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option12->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option12->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option12 = rate_NewLayer1_Option12->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option13->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option13->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option13 = rate_NewLayer1_Option13->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option14->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option14->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option14 = rate_NewLayer1_Option14->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option15->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option15->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option15 = rate_NewLayer1_Option15->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option16->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option16->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option16 = rate_NewLayer1_Option16->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option17->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option17->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option17 = rate_NewLayer1_Option17->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option18->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option18->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option18 = rate_NewLayer1_Option18->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option19->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option19->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option19 = rate_NewLayer1_Option19->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option20->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option20->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option20 = rate_NewLayer1_Option20->GetBinLowEdge(i);
  	  break;
  	}
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option21->GetNbinsX() ; ++i)
    {
      // cout<<"rate_NewLayer1_Option21->GetBinContent(i) = "<<rate_NewLayer1_Option21->GetBinContent(i)<<endl;
      if(rate_NewLayer1_Option21->GetBinContent(i)<=Target)
      	{
      	  Threshold_NewLayer1_Option21 = rate_NewLayer1_Option21->GetBinLowEdge(i);
      	  break;
      	}
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option22->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option22->GetBinContent(i)<=Target)
      	{
      	  Threshold_NewLayer1_Option22 = rate_NewLayer1_Option22->GetBinLowEdge(i);
      	  break;
      	}
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option23->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option23->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option23 = rate_NewLayer1_Option23->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option24->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option24->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option24 = rate_NewLayer1_Option24->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option25->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option25->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option25 = rate_NewLayer1_Option25->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option26->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option26->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option26 = rate_NewLayer1_Option26->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option27->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option27->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option27 = rate_NewLayer1_Option27->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option28->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option28->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option28 = rate_NewLayer1_Option28->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option29->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option29->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option29 = rate_NewLayer1_Option29->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option30->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option30->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option30 = rate_NewLayer1_Option30->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option31->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option31->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option31 = rate_NewLayer1_Option31->GetBinLowEdge(i);
          break;
        }
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option31_extrap->GetNbinsX() ; ++i)
    {
      // cout<<"rate_NewLayer1_Option22->GetBinContent(i) = "<<rate_NewLayer1_Option22->GetBinContent(i)<<endl;
      if(rate_NewLayer1_Option31_extrap->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option31_extrap = rate_NewLayer1_Option31_extrap->GetBinLowEdge(i);
          break;
        }
    }
  
  cout<<"Double_t Threshold_NewLayer1_noIso   = "<<Threshold_NewLayer1_noIso-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option1 = "<<Threshold_NewLayer1_Option1-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option2 = "<<Threshold_NewLayer1_Option2-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option3 = "<<Threshold_NewLayer1_Option3-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option4 = "<<Threshold_NewLayer1_Option4-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option5 = "<<Threshold_NewLayer1_Option5-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option6 = "<<Threshold_NewLayer1_Option6-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option7 = "<<Threshold_NewLayer1_Option7-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option8 = "<<Threshold_NewLayer1_Option8-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option9 = "<<Threshold_NewLayer1_Option9-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option10 = "<<Threshold_NewLayer1_Option10-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option11 = "<<Threshold_NewLayer1_Option11-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option12 = "<<Threshold_NewLayer1_Option12-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option13 = "<<Threshold_NewLayer1_Option13-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option14 = "<<Threshold_NewLayer1_Option14-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option15 = "<<Threshold_NewLayer1_Option15-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option16 = "<<Threshold_NewLayer1_Option16-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option17 = "<<Threshold_NewLayer1_Option17-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option18 = "<<Threshold_NewLayer1_Option18-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option19 = "<<Threshold_NewLayer1_Option19-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option20 = "<<Threshold_NewLayer1_Option20-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option21 = "<<Threshold_NewLayer1_Option21-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option22 = "<<Threshold_NewLayer1_Option22-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option23 = "<<Threshold_NewLayer1_Option23-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option24 = "<<Threshold_NewLayer1_Option24-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option25 = "<<Threshold_NewLayer1_Option25-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option26 = "<<Threshold_NewLayer1_Option26-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option27 = "<<Threshold_NewLayer1_Option27-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option28 = "<<Threshold_NewLayer1_Option28-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option29 = "<<Threshold_NewLayer1_Option29-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option30 = "<<Threshold_NewLayer1_Option30-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option31 = "<<Threshold_NewLayer1_Option31-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option31_extrap = "<<Threshold_NewLayer1_Option31_extrap-0.49<<";"<<endl;
  cout<<endl;
  cout<<"TString Threshold_NewLayer1_noIso = \""<<Threshold_NewLayer1_noIso<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option1 = \""<<Threshold_NewLayer1_Option1<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option2 = \""<<Threshold_NewLayer1_Option2<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option3 = \""<<Threshold_NewLayer1_Option3<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option4 = \""<<Threshold_NewLayer1_Option4<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option5 = \""<<Threshold_NewLayer1_Option5<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option6 = \""<<Threshold_NewLayer1_Option6<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option7 = \""<<Threshold_NewLayer1_Option7<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option8 = \""<<Threshold_NewLayer1_Option8<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option9 = \""<<Threshold_NewLayer1_Option9<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option10 = \""<<Threshold_NewLayer1_Option10<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option11 = \""<<Threshold_NewLayer1_Option11<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option12 = \""<<Threshold_NewLayer1_Option12<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option13 = \""<<Threshold_NewLayer1_Option13<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option14 = \""<<Threshold_NewLayer1_Option13<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option15 = \""<<Threshold_NewLayer1_Option15<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option16 = \""<<Threshold_NewLayer1_Option16<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option17 = \""<<Threshold_NewLayer1_Option17<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option18 = \""<<Threshold_NewLayer1_Option18<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option19 = \""<<Threshold_NewLayer1_Option19<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option20 = \""<<Threshold_NewLayer1_Option20<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option21 = \""<<Threshold_NewLayer1_Option21<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option22 = \""<<Threshold_NewLayer1_Option22<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option23 = \""<<Threshold_NewLayer1_Option23<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option24 = \""<<Threshold_NewLayer1_Option23<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option25 = \""<<Threshold_NewLayer1_Option25<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option26 = \""<<Threshold_NewLayer1_Option26<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option27 = \""<<Threshold_NewLayer1_Option27<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option28 = \""<<Threshold_NewLayer1_Option28<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option29 = \""<<Threshold_NewLayer1_Option29<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option30 = \""<<Threshold_NewLayer1_Option30<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option31 = \""<<Threshold_NewLayer1_Option31<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option31_extrap = \""<<Threshold_NewLayer1_Option31_extrap<<"\";"<<endl;
}
