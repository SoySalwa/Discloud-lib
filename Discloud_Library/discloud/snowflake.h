#pragma once
#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <cstdint>

namespace dcl {
    class snowflake {
    public:
        snowflake(const uint64_t& identifier) : identifier(identifier) {}
     
        std::string to_string() const {
            return std::to_string(identifier);
        }

    private:
        uint64_t identifier;
    };
}


#endif // !SNOWFLAKE_H