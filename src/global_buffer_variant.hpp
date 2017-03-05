#ifndef GLOBAL_BUFFER_VARIANT_HPP
#define GLOBAL_BUFFER_VARIANT_HPP

#include <map>
#include "global_buffers.hpp"

constexpr size_t max_buffer = 1048576;
auto global_buffers = makeBuffers<2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576>();
constexpr size_t args_num = std::tuple_size<decltype(global_buffers)>::value;


std::map<size_t, size_t> gen_args_map(const size_t args) {
	std::map<size_t, size_t> loc_map;
	for(size_t i =0; i < args; ++i) {
		loc_map.emplace_hint(loc_map.end(), std::make_pair(static_cast<size_t>(2<<i), i));
	}
	return loc_map;
}
// args map is a wrapper from size (powers of 2) to index in global buffers
// index [0] size [2]
// index [1] size [4]
// ...
// index [10] size [2048]
// ... to args_num (index)
std::map<size_t, size_t> args_map = gen_args_map(args_num);

class chunk_visitor : public boost::static_visitor<std::vector<std::vector<char>>> {
public:
	chunk_visitor(size_t threads) : threads_num(threads), splitted(false) {}

	std::vector<std::vector<char>> operator()(std::array<char,2> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(2);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,4> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(4);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,8> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(8);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,16> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(16);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,32> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(32);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,64> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(64);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,128> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(128);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,256> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(256);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,512> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(512);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,1024> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(1024);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,2048> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(2048);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,4096> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(4096);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,8192> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(8192);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,16384> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(16384);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,32768> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(32768);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,65536> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(65536);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,131072> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(131072);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,262144> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(262144);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,524288> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(524288);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	std::vector<std::vector<char>> operator()(std::array<char,1048576> &arr) {
		std::vector<char> msg_vec; msg_vec.reserve(1048576);
		msg_vec.assign(arr.begin(),arr.end());
		split_if(msg_vec);
		return splitted_msg;
	}
	void split_if(std::vector<char> msg_vec) {
		std::lock_guard<std::mutex> lock(split_mtx);
		if (!splitted) {
			splitted_msg = split_char_vector(msg_vec, threads_num);
			splitted = true;
		}
	}

private:
	size_t threads_num;
	bool splitted;
	static std::mutex split_mtx;
	std::vector<std::vector<char>> splitted_msg;
};
std::mutex chunk_visitor::split_mtx;

#endif // GLOBAL_BUFFER_VARIANT_HPP