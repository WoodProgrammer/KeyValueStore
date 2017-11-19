###rabbitmq handler

#### 1-) request vote channel (host_ip)
#### 2-) send vote channel send_vote (host_ip,dest_ip)

import pika


class Voting:
    def __init__(self):
        self.voting_flag = 0
        self.credentials = pika.PlainCredentials('user', 'password')
        self.parameters = pika.ConnectionParameters('localhost',
                                            5672,
                                            '/',
                                            self.credentials)
                        
        self.connection = pika.BlockingConnection(self.parameters)
        self.channel = self.connection.channel()    
        self.channel.queue_declare(queue='election') ##send the vote 
        self.channel.queue_declare(queue='receive_') ## request the vote s
  
    def request_vote(self):
        self.channel.basic_publish(exchange='',
                      routing_key='receive_',
                      body='Hello World!')


    def count_voting_result(self): ##consumer
        self.channel.basic_consume(self.send_vote,
                      queue='election',
                      no_ack=True)


    def send_vote(self,ch, method, properties, body):## it send vote
        
        self.channel.basic_publish(exchange='',
                      routing_key='election',
                      body='{}'.format(body))

        print(body)






    def receive_vote_req(self): ### it receive request.

        self.channel.basic_consume(self.send_vote,
                      queue='receive_',
                      no_ack=True)
