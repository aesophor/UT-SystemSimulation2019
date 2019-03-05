// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

// Network token for token based access scheme simulation.
// A network node is allowed to transmit packets if and only if
// it holds the token.

#ifndef TOKEN_H_
#define TOKEN_H_

class Token {
public:
    Token();
    virtual ~Token() = default;

private:

};

#endif
