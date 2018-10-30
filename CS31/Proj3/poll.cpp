#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;


bool isValidUppercaseStateCode(string stateCode)
{
  // checks that the state code is valid
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
        "LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
        "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}

int stuffandthings(string whatshappening)
{
  // Returns a 0 or a 1 on the basis of if a comma-enclosed component is right
  int k = 0;
  int j = whatshappening.size() - 1;
  string what;
  char d;
  if(whatshappening == "")
    return 1;
  for(int i=0; i<2; i++){
      d = whatshappening[i];
      what += toupper(d);
  }
  if(isValidUppercaseStateCode(what))
    k += 1;
  while( j != 1 && j != -1){
    switch(whatshappening[j]){
    case 'R':
    case 'D':
    case 'I':
    case 'i':
    case 'r':
    case 'd':
      j--;
      if(isdigit(whatshappening[j])) {
	while(isdigit(whatshappening[j])){
	  j--;
	}
      }
      else{
	k *= 0;
	j = -1;
      }
      break;
    default: k*=0; j = -1;
			 }
    }
    return k;
}

bool hasProperSyntax(string omgwhat){
  //multiplies all the comma-separated components' stuffandthings results: if any one component
  //is invalid, the result multiplies to 0, otherwise it's 1 and is proper syntax
  int k=1;
  string wow;
  for(int i=0; i != omgwhat.size();i++){
    if( omgwhat[i] == ',' )
      {
  	k *= stuffandthings(wow);
        wow = "";
  	continue;
      }
    wow += omgwhat[i];
  }
  k *= stuffandthings(wow); 
  return (k == 1);
  // return (stuffandthings(omgwhat) == 1);
  // this is just stuff I'm using to test stuffandthings
}

int countthings(string ermahgerd, char suchwow)
{
  // essentially follows the same procedure as the previous set, it'll count componentwise and tallyseats calls
  // for each component: easier because it just recursively adds to seats, though the posted
  // solutions will probably be cleaner. I'm not very good at this stuff.
  int lolz = 0;
  for(int i = ermahgerd.size() - 1; i > 1; i--){
    if(ermahgerd[i] != suchwow)
      continue;
    for(int j = i-2; j>1 && j<i ; j++){
      if( isdigit(ermahgerd[j]) ){
	lolz *= 10;
	lolz += (ermahgerd[j] - '0');
	continue;
      }
    }
  }
  return lolz;
}
  

int tallySeats(string pollData, char party, int& seatTally)
{
  string wow;
  if(!hasProperSyntax(pollData))
    return 1;
  else if(toupper(party) != 'D' || toupper(party) != 'R' || toupper(party) != 'I')
    return 2;
  for(int i = 0; i != pollData.size();i++){
    if( pollData[i] == ',' )
      {
  	seatTally += countthings(wow, party);
        wow = "";
  	continue;
      }
    wow += pollData[i];
  }
  seatTally += countthings(wow,party);
  return 0;
 }

int main()
{
  string pollstring;
  char party;
  int seats = 0;
  cout << "Enter a poll string:";
  getline(cin, pollstring);
  cout << hasProperSyntax(pollstring) << endl;
  cout << "Enter a party code:";
  cin >> party;
  tallySeats(pollstring, party, seats);
  cout << "Predicted seats for " << party << " is " << seats << endl;  

}


  
