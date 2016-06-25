/*! \file mapfile.h
 *
 * \brief Read a map file
 *
 * \author Christian Rößner <c@roessner.co>
 * \version 1606.1.0
 * \date 2016-06-10
  * \copyright Copyright 2016 Christian Roessner <c@roessner.co>
 */

#ifndef SRC_MAP_H_
#define SRC_MAP_H_

#include <string>
#include <map>
#include <vector>

extern bool debug;

namespace mapfile {
    typedef std::map<std::string, std::string> certstore_t;

    typedef std::vector<std::string> split_t;

    enum class Smime {CERT, KEY};

    class Map {
    public:
        Map(const std::string &);

        virtual ~Map() = default;

        static void readMap(const std::string&);

        const std::string & getCert(void);

        const std::string & getKey(void);

    private:
        void setSmimeFiles(
                const Smime &, const split_t &, const std::string &, size_t);

        void getSmimeParts(const Smime &);

        static certstore_t certstore;

        static bool mapLoaded;

        const std::string mailfrom;

        std::string smimecert;

        std::string smimekey;
    };
}  // namespace mapfile

#endif  // SRC_MAP_H_