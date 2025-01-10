#!/bin/bash

echo "42"
./convert '42'
echo "------------------------"
echo "0"
./convert '0'
echo "------------------------"
echo "-123"
./convert '-123'
echo "------------------------"
echo "42.0f"
./convert '42.0f'
echo "------------------------"
echo "3.14f"
./convert '3.14f'
echo "------------------------"
echo "-42.42"
./convert '-42.42'
echo "------------------------"
echo "a"
./convert 'a'
echo "------------------------"
echo "nan"
./convert nan
echo "------------------------"
echo +inf
./convert +inf
echo "------------------------"
echo "abc"
./convert 'abc'
echo "------------------------"
echo "2147483648"
./convert '2147483648'
echo "------------------------"