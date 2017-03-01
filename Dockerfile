FROM debian:8

MAINTAINER <ale-batt@student.42.fr>

RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y traceroute

ADD . /app
WORKDIR /app

RUN cd /app && make fclean && make

ENTRYPOINT ["/app/ft_ping"]
