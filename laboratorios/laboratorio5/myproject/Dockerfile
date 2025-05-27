# Dockerfile

FROM python:3.10-slim

WORKDIR /app

COPY requirements.txt /app/

# Instalar el cliente de PostgreSQL para usar pg_isready
RUN apt-get update && apt-get install -y postgresql-client && rm -rf /var/lib/apt/lists/*

RUN pip install --upgrade pip
RUN pip install -r requirements.txt

COPY . /app/

EXPOSE 8000

CMD ["sh", "-c", "until pg_isready -h db -p 5432; do echo 'Waiting for Postgres...'; sleep 2; done; python manage.py migrate && python manage.py runserver 0.0.0.0:8000"]
