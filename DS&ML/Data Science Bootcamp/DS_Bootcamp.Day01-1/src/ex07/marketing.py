#python3 marketing.py call_center
#python3 marketing.py loyalty_program
#python3 marketing.py potential_clients

import sys
def emails():
    clients = ['andrew@gmail.com', 'jessica@gmail.com', 'ted@mosby.com',
                'john@snow.is', 'bill_gates@live.com', 'mark@facebook.com',
                'elon@paypal.com', 'jessica@gmail.com']
    
    participants = ['walter@heisenberg.com', 'vasily@mail.ru',
                'pinkman@yo.org', 'jessica@gmail.com', 'elon@paypal.com',
                'pinkman@yo.org', 'mr@robot.gov', 'eleven@yahoo.com']
    
    recipients = ['andrew@gmail.com', 'jessica@gmail.com', 'john@snow.is']

    return clients, participants, recipients

def send_call_center(clients, recipients):
    return list(clients - recipients)

def send_loyalty_program(clients, participants):
    return list(clients - participants)

def send_potential_clients(clients, participants):
    return list(participants - clients)

def send(command):

    clients, participants, recipients = emails()
    

    if command == "call_center":
        print(send_call_center(set(clients), set(recipients)))
    elif command == "loyalty_program":
        print(send_loyalty_program(set(clients), set(participants)))
    elif command == "potential_clients":
        print(send_potential_clients(set(clients), set(participants)))
    else:
        print(ValueError('Unknown command'))


if __name__ == "__main__":
    
    if(len(sys.argv) == 2):
        send(sys.argv[1])
    else:
        print(ValueError('Unknown command'))
