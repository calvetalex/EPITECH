FROM node:12-alpine3.9

WORKDIR /app

COPY ./ /app
RUN npm install

EXPOSE 80

CMD ["node", "server.js"]