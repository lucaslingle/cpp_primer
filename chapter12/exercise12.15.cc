/*
Rewrite the previous exercise to use a lambda instead of end_connection.
*/

struct destination;
struct connection;
connection connect(destination*);
void disconnect(connection);

void f(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection* pc) -> void { disconnect(*pc); });
    // when f exists even by exception the connection will be properly closed
}
