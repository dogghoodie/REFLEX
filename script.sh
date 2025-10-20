g++ src/main/cpp/main.cpp -o reflex /usr/lib/x86_64-linux-gnu/libncurses.a /usr/lib/x86_64-linux-gnu/libtinfo.a -static

mv reflex ~/.scripts/reflex

echo "alias reflex='~/.scripts/reflex'" >>~/.bashrc
