/**
 * @file Queue.cpp
 * @author Edison
 * @brief Encolador de mensajes para main
 * @version 1.0
 * @date 2021-01-05
 * 
 * @copyright DataAnalitic S.A. (c) {2020}
 * 
 */

#include "Arduino.h"
#include "Queue.h"


//Message functions

/**
 * [Message::set_ID description]
 * @param _id [description]
 */
void Message::set_subject(String _subject){
   Subject = _subject;
}

/**
 * [Message::set_priority description]
 * @param _priority [description]
 */
void Message::set_priority(int _priority){
   priority = _priority;
}

/**
 * [Message::set_pushed description]
 * @param _pushed [description]
 */
void Message::set_pushed(int _pushed){
   pushed = _pushed;
}

/**
 * [Message::set_data description]
 * @param _data [description]
 */
void Message::set_data(String _data){
   data = _data;
}

/**
* [Message::set_timestamp description]
* @return [description]
*/
void Message::set_timestamp(DateTime _now){
   timestamp = TimeSpan(_now.day(),
   _now.hour(),
   _now.minute(),
   _now.second());
}

/**
 * [Message::get_ID description]
 * @return [description]
 */
String Message::get_subject(){
   return Subject;
}

/**
 * [Message::get_priority description]
 * @return [description]
 */
int Message::get_priority(){
   return priority;
}

/**
 * [Message::get_data description]
 * @return [description]
 */
String Message::get_data(){
   return data;
}

/**
 * [Message::get_pushed description]
 * @return [description]
 */
int Message::get_pushed(){
   return pushed;
}

/**
 * [Message::get_timestamp description]
 * @return [description]
 */
TimeSpan Message::get_timestamp(){
   return timestamp;
}


int Message::get_age(DateTime now){
  DateTime difference = DateTime(now - timestamp);
  return difference.minute()*60+difference.second();
}
/**
 * [Message::to_string description]
 * @return [description]
 */
String Message::to_string(){

  return "{SUBJ:"+Subject+","+"priority:"+String(priority)+","+"pushed:"+String(pushed)+","+"data:"+data+"}";
}

//Queue functions

/**
 * [Queue::push description]
 * @param msg [description]
 */
void Queue::push(Message msg){
  msg.set_pushed(msg.get_pushed()+1);
  queue.InsertTail(msg);
}

/**
 * [Queue::requeue description]
 * @param msg [description]
 */
void Queue::requeue(Message msg){
  queue.InsertHead(msg);
}

/**
 * [Queue::pop description]
 * @return [description]
 */
Message Queue::pop(){
  Message first;

  if (queue.GetSize()==1){
    first = queue.GetTail();
    queue.RemoveTail();
  }

  else{
    first = queue.GetHead();
    queue.RemoveHead();
  }

  return first;
}

/**
 * [Queue::is_empty description]
 * @return [description]
 */
bool Queue::is_empty(){
  return queue.GetSize()==0;
}

/**
 * [Queue::sort description]
 */
void Queue::sort(){
  int pass;
}

/**
 * [Queue::get_size description]
 * @return [description]
 */
int Queue::get_size(){
  return queue.GetSize();
}

/**
 * [Queue::to_string description]
 * @return [description]
 */
String Queue::to_string(){

  String data;


  if (is_empty()){
    data = "";
  }

  else if (queue.GetSize()==1){
    data = queue.GetTail().to_string();
  }

  else{
    for (int i = 0 ; i< queue.GetSize(); i++){
      String info = queue.GetAt(i).to_string();
      data = data + info + "\n";
    }
  }


  return data;
}
