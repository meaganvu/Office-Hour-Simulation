#ifndef STUDENT_H
#define STUDENT_H
int priorityNumber(){
  int t;
  for (int i = 0; i < 1; i++){
    t= rand() % 10 +1;
  }
  return t;
}

int help(){
  int t;
  for (int i = 0; i < 1; i++){
    t= rand() % 5  +1;
  }
  return t;
}


class student{
private:
  string name;
  string topic;
  int stuNumber;
  int helpTime;
  int priority;
  //WHEN THEY CAME TO OFFICE HOURS
  int joinedWait;
  int waitTime;
public:
    student(){
      name = "tf";
      topic = "tf";
      waitTime=0;
      stuNumber=0;
      helpTime=0;
      priority=0;
      //WHEN THEY CAME TO OFFICE HOURS
      joinedWait=0;
    }
  student(string n, string top, int t, int j){
    name = n;
    topic = top;
    joinedWait = j;
    stuNumber = t;
    helpTime = help();
    priority = priorityNumber();
    waitTime = 0;
  }
  void operator=(student RHS){
    name = RHS.name;
    topic = RHS.topic;
    waitTime = RHS.waitTime;
    stuNumber = RHS.stuNumber;
    helpTime = RHS.helpTime;
    priority = RHS.priority;
    joinedWait = RHS.joinedWait;
  }
  bool operator<(student RHS){
    if (priority < RHS.priority){
      return 1;
    }
    else{
      return 0;
    }
  }
  bool operator>(student RHS){
    if (priority > RHS.priority){
      return 1;
    }
    else{
      return 0;
    }
  }
  string getTopic(){
    return topic;
  }
  string getName(){
    return name;
  }

  int getNum(){
      return stuNumber;
  }
  void setWait(int t){
      waitTime = t;
  }
  int getWait(){
    return waitTime;
  }
  int getHelp(){
    return helpTime;
  }
  int getJoin(){
    return joinedWait;
  }
  int getPriority(){
    return priority;
  }

};


int wait(student temp, int i){
  int t = i -temp.getJoin();
  return t;
}

#endif
