PROTOC = protoc
target = main
objects = http.pb.o main.o

.PHONY: all clean

all: $(target)

%.pb.cc: %.proto
	$(PROTOC) --cpp_out . $<

$(objects): %.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(target): $(objects)
	$(CXX) $(LDFLAGS) $(LD_LIBS) $^ /usr/local/lib/libprotobuf.a -o $@

clean:
	$(RM) $(target) $(objects) *.pb.h *.pb.cc
