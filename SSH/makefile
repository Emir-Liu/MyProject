

serverip	= 66.42.66.21

ssh_username	= root
ssh_password	= 3_ySCgA\(Z\#4J3]H?
server_port	= 5024
local_address	= 127.0.0.1
local_port	= 1080
password	= lymlovezjj
method		= aes-256-cfb
timeout		= 300
fast_open	= true
serveraccount	= root

.PHONY:check server local connect	

check :
	#检测是否能够连接到服务器
	ping $(serverip)

server:	connectscp connectssh
	#一键配置,启动服务器端

local:	startlocal
	#一键启动客户端

connectscp:	
	#将配置服务器的脚本通过scp发送到服务器上
	./connectscp.sh $(ssh_username) $(serverip) $(ssh_password)

connectssh:	
	#通过ssh连接服务器运行配置服务器的脚本,停留在远程连接界面，以便于观察
	./connectssh.sh $(ssh_username) $(serverip) $(ssh_password)

connect:
	#通过ssh进入服务器
	./connect.sh $(ssh_username) $(serverip) $(ssh_password)
	ssh $(serveraccount)@$(serverip)

startserver:	buildserver createserverconfig
	#启动服务器端shadowsocks
	ssserver -c shadowsocks.json -d stop
	ssserver -c shadowsocks.json -d start

startlocal:	createlocalconfig
	#启动客户端shadowsocks
	sslocal -c shadowsocks.json -d stop
	sslocal -c shadowsocks.json -d start

buildserver:	
	#在服务器端，更新apt，下载shadowsocks
	apt-get --yes --force-yes update
	apt --yes --force-yes install shadowsocks

createserverconfig:
	#创建服务器端shadowsocks的配置文件
	echo "{\n\"server\":\"0.0.0.0\",\n\"server_port\":$(server_port),\n\"password\":\"$(password)\",\n\"method\":\"$(method)\"\n}" > shadowsocks.json

createlocalconfig:
	#创建客户端shadowsocks的配置文件
	echo "{\n\"server\": \"$(serverip)\",\n\"server_port\": $(server_port),\n\"local_address\": \"$(local_address)\",\n\"local_port\": \"$(local_port)\",\n\"password\": \"$(password)\",\n\"method\": \"$(method)\",\n\"timeout\": $(timeout),\n\"fast_open\": $(fast_open)\n}" > shadowsocks.json

