# UPM - Unified Package Manager

The intention is to provide to remove the added friction of inconsistent interfaces when using multiple package managers (flatpak, snap, apt, etc) on a single system, by providing an consistent CLI interface to use all of them, at once if desired. This project was heavily inspire by Bedrock Linux's PMM.

This differs from other 'meta' package managers by providing a way to add new package manager interface to UPM via a configuration file, to remove the need for the end user to add code and recompile the project. I make the assumption that someone who has enough package managers on a single system to warrent using this would also be likely to use one that may be more niche and is less likely to be supported by default.