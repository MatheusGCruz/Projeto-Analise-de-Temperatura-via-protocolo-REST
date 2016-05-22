# CONECTANDO AO ARDUINO COM IP FINAL 255
temperatura = None

timeout = 3 # timeout in seconds
msg = "requerendo temperatura"

host = "192.168.1.255"
print ("Conectando ao Arduino " + host)

port = 23

s = socket(AF_INET, SOCK_STREAM)
print "Socket feito"

ready = select.select([s],[],[],timeout)


s.connect((host,port))
print("Conectado ao arduino " + host)


# RECEBENDO AS INFORMAÇÕES DO ARDUINO

if ready[0]:        
    print("[INFO] Enviando mensagem ao arduino " + host)
    s.sendall(msg)
    print("[INFO] Mensagem enviada ao arduino " + host)

    temperatura = s.recv(4096)
    print("[INFO] Temperatura recebida do arduino " + host)
    print temperatura

#CODIGO DE FUNÇÃO REST RETORNANDO A TEMPERATURA

@app.route('/')
def api_root():
    return temperatura
