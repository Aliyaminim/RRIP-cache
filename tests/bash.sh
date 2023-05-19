#!/bin/bash

echo Testing has started!
echo 
echo "Recency friendly access pattern tests:"
for i in recency_friendly_access_pattern/*.in; do echo $i; done
echo 
echo "Thrashing access pattern tests:"
for i in thrashing_access_pattern/*.in; do echo $i; done
echo 
echo "Mixed access pattern(1) tests:"
for i in mixed_access1_pattern/*.in; do echo $i; done
echo 
echo "Mixed access pattern(2) tests:"
for i in mixed_access2_pattern/*.in; do echo $i; done