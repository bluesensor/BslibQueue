/**
 * @file Queue.h
 * @author Edison
 * @brief Encolador de mensajes para main
 * @version 1.0.1
 * @date 2021-04-13
 * 
 * @copyright DataAnalitic (c) {2021}
 * 
 */

#ifndef Queue_h

#define Queue_h

#include <LinkedListLib.h>
#include "RTClib.h"
#include "Arduino.h"


#define DEFAULT_SUBJ "NO"
#define DEFAULT_PRIO 0
#define EMPTY_DATA ""
#define START_ID 0
#define START_PUSHED_T 0

//Some Subjects
#define ARRIVED "A"
#define TO_SEND "S"

/**
 * [Message description]
 */

class Message{
  private:

    String Subject;                                                             //Message Subject
    int priority;                                                               //Message Priority
    String data;                                                                //Message Data


    uint8_t pushed;                                                             //Message's Pushed Time
    TimeSpan timestamp;                                                         //Message's Timestamp

  public:

    Message():
    Subject(DEFAULT_SUBJ),
    priority(DEFAULT_PRIO),
    data(EMPTY_DATA),
    timestamp(TimeSpan(0,0,0,0)),
    pushed(START_PUSHED_T) {}                                                   //Constructor

    void set_subject(String _subject);
    void set_priority(int _priority);
    void set_data(String _data);
    void set_pushed(int _pushed);
    void set_timestamp(DateTime _now);

    String get_subject();
    int get_priority();
    String get_data();
    int get_pushed();
    TimeSpan get_timestamp();

    int get_age(DateTime now);
    String to_string();
};

/**
 * [BslibQueue description]
 */

class BslibQueue{
  private:

    LinkedList<Message> queue ;                                                 //LinkedList of BslibQueue

  public:

    BslibQueue() {}                                                                  //Constructor

    void push(Message msg);
    void requeue(Message msg);
    Message pop();
    bool is_empty();
    int get_size();
    void sort();
    String to_string();

};


#endif
