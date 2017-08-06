/*2D
 *sky is horizontal line 
 *generate rays uniformly along sky 
 *generate angles isotropically (costheta uniform)
 *bin*/
 void CosmicRayAnglesToy(){
	 const int Nsamples = 200000;
	 const double height = .5;
	 TCanvas *c = new TCanvas();
	 TH1D *h = new TH1D("","",200,-2.,2.);
	 TRandom3 *rng = new TRandom3(1);
	 for(int i=0;i<Nsamples;i++){
		 Double_t x = rng->Uniform(-1,1); //position along sky
		 //Double_t cos = rng->Uniform(.34,1);   // flat earth isotropic azimuth
		 Double_t cos = rng->Uniform();   // isotropic azimuth
		 //cos = 1 - pow(cos,1.7);
		 Int_t  sign = (Int_t)(rng->Uniform(0,2))*2-1; //to the left to the right 
		 Double_t ground = x + sign*height*(1-cos*cos); //point where it touches
		 h->Fill(ground);
	 }
	 h->Draw();
 }