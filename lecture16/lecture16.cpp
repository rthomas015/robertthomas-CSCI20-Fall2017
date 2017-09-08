//Created By: April Browne
 //Created On: 8/22/2016
 
 //important - preprocessor directives needed to input/output information
 #include <iostream>
 using namespace std;
 
 //important - creates the monster struct and exists before the main() function
 struct monster{
  string head;
  string eyes;
  string ears;
  string mouth;
  string nose;
 };
 
 //create a place for the object to exist
 struct realm {
  //size in meters
  double width;
  double length;
  double height;
  string terrain_type;
  string proper_name;
 };
 
 int main()
 {
   //creates instance of monster called 'monsterA' and assigns values to its attributes
   monster monsterA;
   //? is it good practice to immediately set all the variables on the instantiated object (within reason)
   monsterA.head = "Zombus";
   monsterA.eyes = "Vegitas";
   monsterA.ears = "Wackus";
   monsterA.nose = "Vegitas";
   monsterA.mouth = "Wackus";
   
   realm Swampville;
   Swampville.proper_name = "Swampville USA";
   Swampville.width = 200.00;
   Swampville.height = 10.00;
   Swampville.length = 200.00;
   Swampville.terrain_type = "swamp";
   
   //? doesn't seem to fit the style outlined in the Zybook since its lacking spaces
   cout<<"Head:"<<monsterA.head<<endl;
   cout<<"Eyes:"<<monsterA.eyes<<endl;
   cout<<"Ears:"<<monsterA.ears<<endl;
   cout<<"Nose:"<<monsterA.nose<<endl;
   cout<<"Mouth:"<<monsterA.mouth<<endl;
   
   cout << endl
        << "MonsterA is hanging out in " << Swampville.proper_name << ". He looks left and right and " << Swampville.width
        << " meters off in the distance he sees an entangled, unpassable mass of vines.";

   //? missing return 0;
}