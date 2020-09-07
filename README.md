What is Zelantus?
----------------

https://zelantus.com

Zelantus is a personal token marketplace. Anybody can create and issue tokens for social media followers, microemployment or just plain fun.


Zelantus is an experimental digital currency that enables instant payments to
anyone, anywhere in the world. Zelantus uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. 



License
-------

Zelantus is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.


Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/ZelantusProject/Zelantus/tags) are created
regularly to indicate new official, stable release versions of Zelantus Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Developer IRC can be found on Freenode at #zelantus-core-dev.


Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

Testnet is now up and running and available to use during development. There is an issue when connecting to the testnet that requires the use of the -maxtipage parameter in order to connect to the test network initially. After the initial launch the -maxtipage parameter is not required.

Use this command to initially start zelantusd on the testnet. <code>./zelantusd -testnet -maxtipage=259200</code>


### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`


### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.


About Zelantus
----------------

Algo: KawPow

Block Reward: 5 ZELS

Max Supply: 21 Million

Block Time: 1 Minute


Zelantus Downloads
----------------

Windows:https://github.com/zelantus/MainNet-critical-fix/releases/download/v4.2/zelantus-mainnet-win64.zip

Linux:https://github.com/zelantus/MainNet-critical-fix/releases/download/v4.2/zelantus-mainnet-linux_x64.tar

Android:https://github.com/zelantus/MainNet-critical-fix/releases/download/v4.2/app-zels-release.apk
