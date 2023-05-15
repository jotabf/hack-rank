// SUBDOMAINS: Debugging

#include <algorithm>
#include <chrono>  // chrono::system_clock::time_point
#include <iostream>
#include <vector>

using namespace std;
//#define Time chrono::system_clock::time_point

class Message {
  // Time _time;
  int id;  
  string _text;
  static int id_count;

 public:
  Message(const string& text) : _text(text) {
    // _time = chrono::system_clock::now();
    id = (++id_count);
  }
  const string& get_text() { return _text; }
  inline bool operator<(const Message& other) const {
    return id < other.id;
  }
};

int Message::id_count = 0;

class MessageFactory {
 public:
  MessageFactory() {}
  Message create_message(const string& text) {
    return Message(text);
  }
};

class Recipient {
 public:
  Recipient() {}
  void receive(const Message& msg) { messages_.push_back(msg); }
  void print_messages() {
    fix_order();
    for (auto& msg : messages_) {
      cout << msg.get_text() << endl;
    }
    messages_.clear();
  }

 private:
  void fix_order() { sort(messages_.begin(), messages_.end()); }
  vector<Message> messages_;
};

class Network {
 public:
  static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in
    // unspecified order
    random_shuffle(messages.begin(), messages.end());
    for (auto msg : messages) {
      recipient.receive(msg);
    }
  }
};

int main() {
  MessageFactory message_factory;
  Recipient recipient;
  vector<Message> messages;
  string text;
  while (getline(cin, text)) {
    messages.push_back(message_factory.create_message(text));
  }
  Network::send_messages(messages, recipient);
  recipient.print_messages();
}
