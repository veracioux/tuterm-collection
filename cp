#!/usr/bin/env tuterm

# tuterm-collection
#
# Copyright (c) 2021 The Tuterm Collection Contributors
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

configure() {
    TUTERM_NAME='cp-tutorial'
}

setup() {
    touch file1
}

delayed-yes() {
    while :; do
        sleep "$DELAY_PROMPT"
        echo "y"
    done
}

run() {
    setup

    M "Say you have a file called 'file1'. Proof:"
    c ls
    M "Let's copy the file into a file called 'file2'"
    c cp file1 file2
    M "You can copy files into a destination directory too."
    M "Let's create a directory first:"
    c mkdir dir1
    M "Now let's copy our existing files there:"
    c cp file1 file2 dir1/
    c ls dir1
    M "Directories can be copied too - let's create dir2 that is identical to dir1"
    c cp dir1 dir2
    M "... but you need to add a --recursive option, or -r for short"
    c cp -r dir1 dir2

    echo
    M "A few useful pieces of information:"
    M "  The last argument is always the destination. All arguments before it are source files/directories."
    M "  Multiple sources are allowed only if the destination is an existing directory."
    echo
    M "Press any key to continue..."
    read -s -n 1
    echo

    M "Let's clean up the working directory a bit (we did the honors for you):"
    rm -rf *
    mkdir dir1
    touch file1 file2 file3 dir1/file1 dir1/file2
    c ls
    M "When used interactively, you want to avoid mistakes that would cause you to permanently overwrite existing files."
    M "Using the --interactive (-i for short) option, you are prompted for confirmation:"
    M "  - enter y for yes"
    M "  - enter n for no"
    if mode tut; then
        c cp -i file1 file2 file3 dir1/
    else
        delayed-yes | cp -i file1 file2 file3 dir1/
        # TODO
    fi
    M "Or, if you don't want to overwrite any files, use --no-clobber (-n for short)"
    c cp -n file1 dir1/

    M "cp can be used to create links as well"
    M "The --link option creates a hard link (-l for short)"
    c cp -l file1 file1-link
    M "The --symbolic-link option creates a symbolic link (-s for short)"
    c cp -s file1 file1-symlink
    M "That's it. For more information, run 'man cp'."
}
