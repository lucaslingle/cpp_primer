/*
Write your own version of a function that uses a shared_ptr 
to manage a connection.
*/

struct destination;
struct connection;
connection connect(destination*);
void disconnect(connection);

void end_connection(connection *p) {
    disconnect(*p);
}

void f(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    // when f exists even by exception the connection will be properly closed
}
