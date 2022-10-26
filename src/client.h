#include <sys/socket.h>
#include <netinet/in.h>
#include <bits/stdc++.h>
#include <arpa/inet.h>

class socket_client{
public:
    bool client_setup(){
        try{
            client_socket = socket(PF_INET, SOCK_DGRAM, 0);
            client_addr.sin_family = AF_INET;
            client_addr.sin_addr.s_addr = inet_addr("");
            client_addr.sin_port = htons(0);
            bind(client_socket, (struct sockaddr*)&client_addr, sizeof(client_addr));
            return true;
        }
        catch(...){
            printf("Client setup failed. Please try again.");
            return false;
        }
    }

    bool server_setup(){
        try{
            server_socket = socket(PF_INET, SOCK_DGRAM, 0);
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = inet_addr("");
            server_addr.sin_port = htons(0);
            bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
            return true;
        }
        catch(...){
            printf("Server setup failed. Please try again.");
            return false;
        }
    }

    unsigned char * recv(){
        socklen_t len = sizeof(sockaddr);
        recvfrom(server_socket, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)& server_addr, &len);
        return recv_buf;
    }

    void listen(){
        while(1){
            recv_data = recv();
            forward(recv_data);
        }
    }

    void forward(unsigned char * data){
        while(1){
            // do something with the data
        }
    }

private:
    static const int MAX_SIZE = 2048*1000;
    unsigned char buf[MAX_SIZE];
    // vector<unsigned char> buf(MAX_SIZE);


    unsigned char * recv_data;
    unsigned char recv_buf[2048];

    unsigned int client_socket;
    struct sockaddr_in client_addr;

    unsigned int server_socket;
    struct sockaddr_in server_addr;

};
