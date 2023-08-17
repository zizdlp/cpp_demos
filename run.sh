docker stop cppdemo
docker rm cppdemo
docker run --name cppdemo -itd -v $(pwd):/home zizdlp/gperf tail -f /etc/hosts
docker exec -it cppdemo bash
