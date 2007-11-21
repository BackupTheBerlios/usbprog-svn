/*
 * (c) 2007, Bernhard Walle <bernhard.walle@gmx.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef USBPROG_H
#define USBPROG_H

#include <stdexcept>

#include <usbprog/firmwarepool.h>
#include <usbprog/devices.h>

/* constants {{{1 */

#define DEFAULT_TERMINAL_WIDTH  80

/* ApplicationError {{{1 */

class ApplicationError : public std::runtime_error {
    public:
        ApplicationError(const std::string& string)
            : std::runtime_error(string) {}
};

/* HashNotifier {{{1 */

class HashNotifier : public ProgressNotifier {
    public:
        HashNotifier(int width);
        ~HashNotifier();

    public:
        int progressed(double total, double now);
        void finished();

    private:
        int m_width;
        int m_lastProgress;
};

/* Usbprog {{{1 */

class Usbprog {
    public:
        Usbprog();
        virtual ~Usbprog();

    public:
        void initConfig()
            throw (ApplicationError);
        void parseCommandLine(int argc, char *argv[]);
        void initFirmwarePool()
            throw (ApplicationError);
        void initDeviceManager()
            throw (ApplicationError);
        void exec()
            throw (ApplicationError);

    protected:
        void printHelp();

    private:
        Firmwarepool *m_firmwarepool;
        std::vector<std::string> m_args;
        DeviceManager *m_devicemanager;
        ProgressNotifier *m_progressNotifier;
};


#endif /* USBPROG_H */

// vim: set sw=4 ts=4 fdm=marker et:
