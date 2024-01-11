#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <vector>

enum class TokenType {
  _return,
  int_lit,
  semi,
};

struct Token {
  TokenType type;
  std::optional<std::string> value{};
};

std::vector<Token> tokenize(const std::string &str) {
  std::vector<char> tokens;

  std::string buf;
  for (int i = 0; i < str.length(); i++) {
    char c = str.at(i);
    if (std::isalpha(c)) {
      buf.push_back(c);
      i++;
      while (std::isalpha(str.at(i))) {
        buf.push_back(str.at(i));
        i++;
      }
      i--;

      if (buf == "return") {
        tokens.push_back({.type = TokenType::_return});
        buf.clear();
      } else {
        std::cerr << "Error" << std::endl;
        exit(EXIT_FAILURE);
      }
    } else if (std::isdigit(c)) {
      buf.push_back(c);
      i++;
      while (std::isdigit(str.at(i))) {
        buf.push_back(str.at(i));
        i++;
      }
      i--;
      tokens.push_back({.type = TokenType::int_lit, .value = buf});
      buf.clear();

    } else if (c == ';') {
      tokens.push_back({.type = TokenType::semi});

    } else if (std::isspace(c)) {
      continue;
    } else {
      std::cerr << "Error" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  return tokens;
}

std::string tokens_to_asm(const std::vector<Token> &tokens) {
  std::stringstream output;
  output << "global _start\nstart:\n";
  for (int i = 0; i < tokens.size(); i++) {
    const Token &token = tokens.at(i);
    if (token.type == TokenType::_return) {
      if (i++ < tokens.size() && tokens.at(i + 1).type == TokenType::int_lit) {
        if (i + 2 < tokens.size() && tokens.at(i + 2).type == TokenType::semi) {
          output << "    mov rax, 60\n";
          output << "    mov rdi, " << tokens.at(i + 1).value.value() << "\n";
          output << "    syscall"
        }
      }
    }
  }
  return output.str();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << std::endl;
    std::cerr << "kitsu <input.nkts>" << std::endl;
    return EXIT_FAILURE;
  }

  std::string contents;
  {
    std::ifstream input(argv[1]); // Use ifstream directly for file input
    if (!input.is_open()) {
      std::cerr << "Error opening file: " << argv[1] << std::endl;
      return EXIT_FAILURE;
    }

    std::stringstream contents_stream;
    contents_stream << input.rdbuf();
    contents = contents_stream.str();
  }

  {
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
      return EXIT_FAILURE;
    }

    std::stringstream contents_stream;
    contents_stream << input.rdbuf();
    contents = contents_stream.str();
  }

  std::vector<Token> tokens = tokenize(contents);
  std::cout << tokens_to_asm(tokens) << std::endl;

  return EXIT_SUCCESS;
}
