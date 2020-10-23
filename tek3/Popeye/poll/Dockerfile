FROM python:3.7-alpine

WORKDIR /poll

ENV FLASK_APP app.py
ENV FLASK_RUN_HOST 0.0.0.0

RUN apk add --no-cache gcc musl-dev linux-headers

COPY requirements.txt requirements.txt

RUN pip3 install -r requirements.txt

EXPOSE 80

COPY . .

CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]