## build stage
FROM maven:3.5-jdk-8-alpine AS builder

WORKDIR /src
COPY ./ /src

RUN mvn dependency:resolve

RUN mvn package

## run stage
FROM openjdk:8-jre-alpine

WORKDIR /src/target

COPY --from=builder /src/target /src/target

CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]