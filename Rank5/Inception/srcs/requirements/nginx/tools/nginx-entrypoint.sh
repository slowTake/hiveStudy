#!/bin/sh
set -e

DOMAIN="${DOMAIN_NAME:-login.42.fr}"

if [ ! -f /etc/nginx/ssl/public_certificate.crt ]; then
	echo "==> Generating self-signed certificate for ${DOMAIN}..."
	openssl req -x509 -nodes -days 365 \
		-out /etc/nginx/ssl/public_certificate.crt \
		-keyout /etc/nginx/ssl/private.key \
		-subj "/C=FI/ST=Uusimaa/L=Helsinki/O=42/OU=Hive/CN=${DOMAIN}"
fi

sed "s/DOMAIN_PLACEHOLDER/${DOMAIN}/g" /etc/nginx/nginx.conf.template > /etc/nginx/nginx.conf

exec nginx -c /etc/nginx/nginx.conf -g 'daemon off;'
