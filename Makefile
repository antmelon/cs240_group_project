CXXFLAGS = -g -Wall -std=c++17

main:	chull.hh wrap.hh main.cc
		g++ $(CXXFLAGS) main.cc -o make-hull

CXX_FILES = $(wildcard *.cc)
TARGETS = $(CXX_FILES:%.cc=%)


all:		$(TARGETS) .gitignore

.phony:		clean

clean:
		rm -f *.o *~ $(TARGETS)

.gitignore:	$(CXX_FILES)
		cat </dev/null >$@
		for t in $(TARGETS); do echo $$t >>$@; done
