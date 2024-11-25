#pragma once

#include <TeenAstroCatalog.h>

// maximum number of catalogs supported
// there is a matching array in subMenuSyncGoto() that also needs adjustment if this is increased
#define MaxCatalogs 64

// ----------------------------------------------------------
// Do not change anything in the structs or arrays below, since they
// have to be in sync with the extraction scripts.

// Struct for catalog header
typedef struct {
  const char           Title[32];
  const char*          Prefix;
  const unsigned short NumObjects;
  const void*          Objects;
  const char*          ObjectNames;
  const char*          ObjectSubIds;
  CAT_TYPES            CatalogType;
  int                  Epoch;
  long                 Index;
} catalog_t;

// Struct for Deep Space Objects (Messier, Herschel, ..etc.)
typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  Obj_type;
  const unsigned short It_subId;
  const unsigned short Obj_id;
  const signed   short Mag;
  const float          RA;
  const float          DE;
} dso_t; 
typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  Obj_type;
  const unsigned short It_subId;
  const unsigned short Obj_id;
  const unsigned char  Mag;
  const unsigned short RA;
  const signed   short DE;
} dso_comp_t; 
typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  Obj_type;
  const unsigned short It_subId;
  const unsigned char  Mag;
  const unsigned short RA;
  const signed   short DE;
} dso_vcomp_t; 

// Struct for general star catalog
typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  BayerFlam; // 0 to 23 are coded Bayer, 24=Invalid, 25 to 255 are the Flamsteed# (for 1 to 231.)
  const unsigned short It_subId;
  const unsigned short Obj_id;   // to 32767
  const signed   short Mag;
  const float          RA;
  const float          DE;
} gen_star_t; 


typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  BayerFlam; // 0 to 23 are coded Bayer, 24=Invalid, 25 to 127 are the Flamsteed# (for 1 to 103.)
  const unsigned short It_subId;
  const unsigned char  Mag;
  const unsigned short RA;
  const signed   short DE;
} gen_star_vcomp_t; 

// Struct for double star catalog
typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  BayerFlam; // 0 to 23 are coded Bayer, 24=Invalid, 25 to 255 are the Flamsteed# (for 1 to 231.)
  const unsigned short It_subId;
  const unsigned short Obj_id;   // to 32767

  const unsigned short Sep;      // separation of components 0.0 to 999.8" (0 to 9998), 999.9 (9999) = Unknown
  const unsigned short PA;        // position angle in degrees, -1 = Unknown
  const signed char    Mag2;

  const signed char    Mag;
  const float          RA;
  const float          DE;
} dbl_star_t; 
typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  BayerFlam; // 0 to 23 are coded Bayer, 24=Invalid, 25 to 255 are the Flamsteed# (for 1 to 231.)
  const unsigned short It_subId;
  const unsigned short Obj_id;   // to 32767

  const unsigned short Sep;      // separation of components 0.0 to 999.8" (0 to 9998), 999.9 (9999) = Unknown
  const unsigned short PA;        // position angle in degrees, 361 = Unknown
  const unsigned char  Mag2;

  const unsigned char  Mag;
  const unsigned short RA;
  const signed   short DE;
} dbl_star_comp_t; // compact, 13 bytes per record

// Struct for variable star catalog
typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  BayerFlam; // 0 to 23 are coded Bayer, 24=Invalid, 25 to 255 are the Flamsteed# (for 1 to 231.)
  const unsigned short It_subId;
  const unsigned short Obj_id;   // to 32767

  const unsigned short Period;   // Period 0.00 to 9.99 days (0 to 999) period 10.0 to 3186.5 days (1000 to 32765), 32766 = Irregular, 32767 = Unknown
  const signed short   Mag2;

  const signed short   Mag;
  const float          RA;
  const float          DE;
} var_star_t; 
typedef struct {
  const unsigned short It_name;
  const unsigned char  Cons;
  const unsigned char  BayerFlam; // 0 to 23 are coded Bayer, 24=Invalid, 25 to 255 are the Flamsteed# (for 1 to 231.)
  const unsigned short It_subId;
  const unsigned short Obj_id;   // to 32767

  const unsigned short Period;   // Period 0.00 to 9.99 days (0 to 999) period 10.0 to 3186.5 days (1000 to 32765), 32766 = Irregular, 32767 = Unknown
  const unsigned char  Mag2;

  const unsigned char  Mag;
  const unsigned short RA;
  const signed   short DE;
} var_star_comp_t; 



// Bayer designation, the Greek letter for each star within a constellation
const char* Txt_Bayer[25] = {
  "Alp","Bet","Gam","Del","Eps","Zet","Eta","The","Iot","Kap","Lam","Mu","Nu","Xi","Omi","Pi","Rho","Sig","Tau","Ups","Phi","Chi","Psi","Ome","?"
};

// Type of object, in the Open NGC database. Do not change the
// order of this, since it has to match what is in Open NGC
const char* Txt_Object_Type[21] = {
  "Galaxy",        "Open Cluster",   "Star",           "Double Star", "Other",      "Galaxy Pair",    "Galaxy Triplet",
  "Galaxy Group",  "Globular Clstr", "Planetary Nbla", "Nebula",      "Hii Region", "Cluster+Nebula", "Asterism",
  "Reflectn Nbla", "SuperNov Rmnt",  "Emission Nbla",  "Non Existant","Nova",       "Duplicate",      "Dark Nebula"
};

//Constellation abbreviation, alphabetical order
const char* Txt_Constellations[89] = {
  "And","Ant","Aps","Aql","Aqr","Ara","Ari","Aur","Boo","CMa","CMi","CVn","Cae","Cam","Cap","Car","Cas","Cen","Cep","Cet","Cha","Cir",
  "Cnc","Col","Com","CrA","CrB","Crt","Cru","Crv","Cyg","Del","Dor","Dra","Equ","Eri","For","Gem","Gru","Her","Hor","Hya","Hyi","Ind",
  "LMi","Lac","Leo","Lep","Lib","Lup","Lyn","Lyr","Men","Mic","Mon","Mus","Nor","Oct","Oph","Ori","Pav","Peg","Per","Phe","Pic","PsA",
  "Psc","Pup","Pyx","Ret","Scl","Sco","Sct","Ser","Sex","Sge","Sgr","Tau","Tel","TrA","Tri","Tuc","UMa","UMi","Vel","Vir","Vol","Vul"," ---"
};

const char* Txt_Constellations_Long[89] = {
  "Andromeda","Antlia","Apus","Aquila","Aquarius","Ara","Aries","Auriga","Boötes","Canis Major","Canis Minor","Canes Venatici","Caelum","Camelopardalis","Capricornus","Carina","Cassiopeia","Centaurus","Cepheus","Cetus","Chamaeleon","Circinus",
  "Cancer","Columba","Coma Berenices","Corona Australis","Corona Borealis","Crater","Crux","Corvus","Cygnus","Delphinus","Dorado","Draco","Equuleus","Eridanus","Fornax","Gemini","Grus","Hercules","Horologium","Hydra","Hydrus","Indus",
  "Leo Minor","Lacerta","Leo","Lepus","Libra","Lupus","Lynx","Lyra","Mensa","Microscopium","Monoceros","Musca","Norma","Octans","Ophiuchus","Orion","Pavo","Pegasus","Perseus","Phoenix","Pictor","Piscis Austrinus",
  "Pisces","Puppis","Pyxis","Reticulum","Sculptor","Scorpius","Scutum","Serpens","Sextans","Sagitta","Sagittarius","Taurus","Telescopium","Triangulum Australe","Triangulum","Tucana","Ursa Major","Ursa Minor","Vela","Virgo","Volans","Vulpecula","---"
};

