RPCGEN server and client code
Dictionary using TRIE, it can consume multiple meaning for a single word.
compile :
$ gcc –o client client.c square_clnt.c square_xdr.c –lnsl
$ gcc –o server server.c square_svc.c square_xdr.c –lrpcsvc -lnsl

execute :
$./server

$ ./client 172.0.0.1
