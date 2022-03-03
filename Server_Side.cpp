#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include "CPP_Word_Letter_Indexer.cpp"

using namespace std;

char header_array[] = "HTTP/1.1 200 OK\r\n"
"Access-Control-Allow-Origin: *\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
;

string query_string;

void start_server() {

    int one = 1;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        cout << "Couldn't bind socket" << endl;
        return;
    }
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));

    // 2. set server address up

    int port = 8000;
    struct sockaddr_in svr_addr;
    svr_addr.sin_family = AF_INET;
    svr_addr.sin_addr.s_addr = INADDR_ANY;
    svr_addr.sin_port = htons(port);

    // 3. bind the server address and socket together
    if (bind(sock, (struct sockaddr*)&svr_addr, sizeof(svr_addr)) == -1){
        close(sock);
        cout << "Could not bind port - port is probably taken" << endl;
    }

    // listen to socket
    listen(sock, 5);

    // wait for client connection
    int client_fd;
    struct sockaddr_in cli_addr;
    socklen_t sin_len = sizeof(cli_addr);

    // buffer
    char buffer[1024] = {0};

    cout << "Waiting for connections" << endl;
    //bool done = false;

    while (1){ // !done
        client_fd = accept(sock, (struct sockaddr*)&cli_addr, &sin_len);
        cout << "New connection" << endl;
        if (client_fd == -1){
            cout << "Connection error" << endl;
        }

        // read from the client
        read(client_fd, buffer, 1024);
        
        string header(buffer);
        //cout << header << endl;

        size_t query_find_start = header.find("/?q=") + 4;
        size_t query_find_end = header.find(" ", query_find_start);

        for (int query_index = query_find_start; query_index < query_find_end; query_index += 1){
            query_string += header[query_index];
        }


        string letters = "abcdefghijklmnopqrstuvwxyz";
        vector<string> candidates;

        squared(query_string, letters, &candidates);

        // write to the client
        string html = "<!DOCTYPE html<html><body><h1> Entered word: " + query_string + " ... " + "Did you mean: " + new_word + "? </h1></body></html>\nDuration(ms): " + to_string(duration.count()) + "\nCandidates: " + to_string(candidates.size());
        char response[sizeof(header_array) + html.size()];
        int i = 0;
        for (char c : header_array){
            response[i++] = c;
        }
        for (char c : html){
            response[i++] = c;
        }

        write(client_fd, response, sizeof(response));
        close(client_fd);

        query_string = "";
        new_word = "";
        html = "";
        //done = true;
    }
}

int main()
{
    start_server();

    return 0;
}