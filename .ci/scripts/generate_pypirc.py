# Copyright(C) 2023-2024 xxxx. All rights reserved.
"""Populate the .pypirc file with the credentials for the PyPi repository."""
import argparse
import configparser


def generate_pypirc(repository, username, password, output_path=".pypirc"):
  config = configparser.ConfigParser()

  if "distutils" not in config:
    config["distutils"] = {}

  if "index-servers" not in config["distutils"]:
    config["distutils"]["index-servers"] = ""

  if "gitlab" not in config["distutils"]["index-servers"]:
    config["distutils"]["index-servers"] += "gitlab"

  if "gitlab" not in config:
    config["gitlab"] = {}

  config["gitlab"]["repository"] = repository
  config["gitlab"]["username"] = username
  config["gitlab"]["password"] = password

  with open(output_path, "w", encoding="utf-8") as configfile:
    config.write(configfile)


def main():
  parser = argparse.ArgumentParser(
      description=
      "Populate the .pypirc file with the credentials for the PyPi repository."
  )
  parser.add_argument(
      "-r",
      "--repository",
      action="store",
      type=str,
      help="The URL of the PyPi repository."
  )
  parser.add_argument(
      "-u",
      "--username",
      action="store",
      type=str,
      help="The username for the PyPi repository."
  )
  parser.add_argument(
      "-p",
      "--password",
      action="store",
      type=str,
      help="The password for the PyPi repository."
  )
  parser.add_argument(
      "-o",
      "--output",
      action="store",
      type=str,
      help="The output file. Default is .pypirc.",
      default=".pypirc"
  )
  args = parser.parse_args()
  generate_pypirc(
      args.repository, args.username, args.password, output_path=args.output
  )


if __name__ == "__main__":
  main()
