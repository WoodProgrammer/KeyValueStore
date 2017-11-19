import socket
class Voting:

    def __init___(self):
        self.sock = socket.socket(family=socket.AF_INET,type=socket.SOCK_STREAM)

    def send_vote(self,candidate_ip,node_obj):

        ###send to candidate 
        server_address = ('{}'.format(candidate_ip),9090)
        self.sock.bind(server_address)
        self.sock.listen(1)
        while True:
            if node_obj.status == 0:
                connection,client_addr = self.sock.accept()
            elif node_obj.status == 1:
                break


    def request_vote(self,node_obj):
        ##broad_casting 
        


        pass