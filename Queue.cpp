/**
 * @file Queue.cpp
 * @author Edison
 * @brief Encolador de mensajes para main
 * @version 1.0.1
 * @date 2021-04-13
 * 
 * @copyright DataAnalitic (c) {2021}
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

//BslibQueue functions

/**
 * [BslibQueue::push description]
 * @param msg [description]
 */
void BslibQueue::push(Message msg){
  msg.set_pushed(msg.get_pushed()+1);
  queue.InsertTail(msg);
}

/**
 * [BslibQueue::requeue description]
 * @param msg [description]
 */
void BslibQueue::requeue(Message msg){
  queue.InsertHead(msg);
}

/**
 * [BslibQueue::pop description]
 * @return [description]
 */
Message BslibQueue::pop(){
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
 * [BslibQueue::is_empty description]
 * @return [description]
 */
bool BslibQueue::is_empty(){
  return queue.GetSize()==0;
}

/**
 * [BslibQueue::sort description]
 */
void BslibQueue::sort(){
  int pass;
}

/**
 * [BslibQueue::get_size description]
 * @return [description]
 */
int BslibQueue::get_size(){
  return queue.GetSize();
}

/**
 * [BslibQueue::to_string description]
 * @return [description]
 */
String BslibQueue::to_string(){

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
