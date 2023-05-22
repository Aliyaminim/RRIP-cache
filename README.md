Project name: RRIP-cache

Contributors: Minimullina Aliya, Samoylov Georgy, Grishin Mikhail.

To install and run the code, follow these steps:

1) git clone git@github.com:Ignitor21/RRIP-cache.git

2) CFLAGS="-O2" make program

3) make test

4) make clean

RRIP is a new replacement policy, which prevents cache blocks with a distant re-reference interval (i.e., scan blocks) from evicting blocks that have a near-immediate re-reference interval (i.e., non-scan blocks). RRIP accomplishes this by requiring an 2-bit register per cache block to store its Rereference Prediction Value (RRPV). We propose Static RRIP (SRRIP) that is scan-resistant.
