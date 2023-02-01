#include <iostream>
using namespace std;
#include <queue>
#include <ctime>
#include <map>
#include "BinaryTree.h"
#include "Student.h"
#include <fstream>
//SOLVE THE ISSUE OF SAME PERSON COMING IN TWICE WITHIN AN OFFICE HOUR!!!

double avg(int w, int stu){
  return w/stu;
}

string randomName(){
  string stuNames[20] = {"Barack Obama", "Micheal Phelps", "Santa Claus", "Jesus Christ", "Ruth Bader Ginsburg","Trisha Paytas", "Your Mom", "Tony Stark", "Winnie The Pooh", "Kris Jenner","The Pink CareBear", "Gerber Baby",
                    "Tony Hawk", "Snoop Dog (The Rapper)", "Snoopy (The Dog)","Kiss Ross", "Chriss Ross", "Kirland", "The Creator of Door Knobs", "Aloe"};
  string t;
  for (int i = 0; i < 1; i++){
    t= stuNames[rand() % 20];
  }
  return t;
}

string randomTopic(){
  string stuTopics[20] = {"Obama Care", "Olympic Swimming","Naughty List", "Turning Water Into Wine","Juding People", "Scandals","Your Dad", "Dying","Eating Too Much Honey and Getting Diabetes", "Trademarking *Momager*","How To Remove Rainbow Tattoo", "Eating Gerber Puffs",
                    "Tutorial On How To Kickflip", "Growing Tree(s)","How To Run Away From An Annoying Bald Kid", "Punching Chriss Ross","Getting Punched By Kiss Ross", "Signature Brand","How To Open Door", "Grape Flum"};
  string t;
  for (int i = 0; i < 1; i++){
      t= stuTopics[rand() % 20];
  }
  return t;
}

string uniqueStu(string arr[], int size){
  cout << "*********  FINDING A UNIQUE NAME ********" <<endl;
  string temp = randomName();
  int count = 1;
  if(size == 0){
    cout << "size = 0: first name is " << temp <<endl;
    return temp;
  }
  else{
  while(count != 0){
    cout <<"finding name " << temp << endl;
  count = 0;
  for(int i = 0; i < size; i++){
    if(temp == arr[i]){
      count++;
    }
  }
  if(count > 0){
    temp=randomName();
  }
}
}
return temp;
}

map<string,string> officeHours(double av[]){
  string arr[20];
  binary_tree_node<student> * waitlist = NULL;
  map<string,string> stuList;
  map<string, string>::const_iterator itter;
//NUMBER FOR WAIT TIME (UPDATE EVERY TIME A STUDENT LEAVES AND PER EVERY MINUTE)
//FOR THE AVERAGE
  int numStu = 0;
  int totalHelp = 0;
  int totalWait = 0;
//KEEPS TRACK OF THE TIME REMAINING ON CURRENT STUDENT
  int timepassed = 0;
  int trackStudent = 1;

  int currHelp = 0;
  int gettingHelped = 0;
//NEED TO FIND HOW LONG EACH PERSON WAITED
  for (int i = 0; i < 60; i++){// need to change this also time accepting students
    if(numStu<20){
    if(rand() % 2==1){
      if(waitlist == NULL){
        string n = uniqueStu(arr, numStu);
        cout <<endl;
        cout << "Unique name is : "<<n<<endl;
        cout <<endl;
        cout << "           MINUTE: " << i <<endl;
        string top = randomTopic();
        stuList.insert(make_pair(n,top));
        student temp(n,top,trackStudent,i);
        waitlist = new binary_tree_node<student>(temp);
        trackStudent ++;
        totalHelp += temp.getHelp();
        arr[numStu] = n;
        numStu++;
      }
      else{
      string n = uniqueStu(arr, numStu);
      cout <<endl;
      cout << "Unique name is : "<<n<<endl;
      cout <<endl;
      cout << "           MINUTE: " << i <<endl;
      string top = randomTopic();
      //cout << n <<" needs to know  " << top <<endl
      stuList.insert(make_pair(n,top));
      student temp(n,top,trackStudent, i); // new student takes in the total wait time a hea
      trackStudent++;
      addList(waitlist, temp); //adds student to waitlist
      cout << "test" <<endl;
      totalHelp += temp.getHelp(); //for average
      arr[numStu] = n;
      numStu++;

    }
    }
  // IF THE FIRST STUDENT DOES NOT SHOW UP AT ITERATION 0
  if(numStu != 0){
    if (timepassed == currHelp&&waitlist==NULL){
      timepassed = 0;
      currHelp =0;
      gettingHelped = 0;
    }
    else if (timepassed == currHelp&&waitlist!=NULL){
    student m(waitlist->data().getName(),waitlist->data().getTopic(),waitlist->data().getNum(), waitlist->data().getJoin());
    m.setWait(wait(m,i));
    totalWait += m.getWait();
    gettingHelped = waitlist->data().getNum();
    currHelp = waitlist->data().getHelp()-1;
    waitlist = removeList(waitlist);

    timepassed = 0;
  }
  else{
      timepassed++;
    }
}
}
  }
//   cout << "------------------------" <<endl;
// cout << "OUTSIDE HOURS" <<endl;
//   cout << "------------------------" <<endl;
//NEED A WHILE LOOP THAT ENDS WHEN THE LIST AND TIMES ARE EMPTY
    int beyondHours =0;
    int i = 60;
    int finalperson;
  while(waitlist != NULL){
    beyondHours++;
      if (timepassed == currHelp){
        finalperson = waitlist->data().getHelp();
        student m(waitlist->data().getName(),waitlist->data().getTopic(),waitlist->data().getNum(), waitlist->data().getJoin());
        m.setWait(wait(m,i));
        totalWait += m.getWait();
      gettingHelped = waitlist->data().getNum();
      currHelp = waitlist->data().getHelp()-1;
      waitlist = removeList(waitlist);
      if(waitlist == NULL){
        beyondHours += finalperson;
      }
      timepassed = 0;
    }
    else{
        timepassed++;
      }

  i++;
}


  cout << "1283710481001238210480129740189409184019" <<endl;
  for (int i = 0; i < numStu; i++){
    cout << arr[i] <<endl;
  }
  cout << "1283710481001238210480129740189409184019" <<endl;
  if(numStu != 0){
  av[0]=beyondHours;
  av[1] = avg(totalWait,numStu);
  av[2] = avg(totalHelp,numStu);
}
else{
  av[0] = 0.0;
  av[1] = 0.0;
  av[2] = 0.0;
}
  return stuList;
}


int main(){
  map <string,string> results;
  map<string, string>::const_iterator itter;
  multimap<string,string> overall;
  double waiting = 0;
  double help = 0;
  double beyond = 0;
  srand(time(NULL));
  for (int i = 0; i < 100; i++){
    cout << "ITTERATION *** " << i << endl;
  double avg[3];
  results = officeHours(avg);
  for(itter = results.begin(); itter!=results.end(); itter++){
    cout<<itter->first<< '\t' << itter->second <<endl;
  }
  cout << endl;
  cout << "-------------------------" <<endl;
  cout << endl;
  for(itter = results.begin(); itter!=results.end(); itter++){
    overall.insert(make_pair(itter->first,itter->second));
  }
    beyond += avg[0];
    //cout <<"BEYOND" << beyond <<endl;
    waiting += avg[1];
    //cout <<"WATIING" <<waiting <<endl;
    help += avg[2];
  //  cout  <<"HELP"<< help <<endl;
  cout << "************************" <<endl;
  }

  cout << "&&&&&&&&&&&&&&&&&&" <<endl;


  for(itter = overall.begin(); itter!=overall.end(); itter++){
    cout<<itter->first<< '\t' << itter->second <<endl;
  }
    ofstream outstream;
    outstream.open("StudentList&Topics.txt");
    if (outstream.fail()){
      cout <<"Error with closing file"<<endl;
      exit (1);
    }
    else{
      for(itter = overall.begin(); itter!=overall.end(); itter++){
          outstream<<itter->first<< '\t' << itter->second <<endl;
      }
    }
    outstream.close();

    cout << "************************" <<endl;
    cout << "beyond average " << beyond/100 <<endl;
    cout << "waiting average " << waiting/100 <<endl;
    cout << "help average " << help/100 <<endl;
    cout << "************************" <<endl;
  return 0;

}
