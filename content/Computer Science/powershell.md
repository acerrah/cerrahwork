---
title: powershell
---
### Understanding PowerShell: A Beginner's Guide

PowerShell is a powerful tool designed by Microsoft to help with system management and task automation. It combines the capabilities of a command-line shell and scripting language, making it a versatile solution for administrators and advanced users.

#### What is Windows PowerShell?

1. **Interactive Command Line Shell**: PowerShell allows you to enter and execute commands interactively, similar to Command Prompt.
2. **Script Language**: It supports scripting, which means you can write scripts to automate tasks.
3. **Cmdlets**: PowerShell introduces a new type of command called cmdlets (pronounced "command-lets"). Cmdlets follow the `Verb-Noun` pattern, like `Get-Process` or `Set-Item`.
4. **Object-Oriented**: PowerShell treats everything as an object, which means commands return objects instead of text. This allows for more powerful and flexible data manipulation.
5. **Integration**: It integrates with .NET, COM, WMI, XML, and Active Directory, providing a wide range of capabilities for system management.

#### How to Invoke PowerShell

- PowerShell comes pre-installed with Windows 7 and later versions.
- To open PowerShell, click `Start`, type `PowerShell`, and press `Enter`.

#### Cmdlets

- **Basic Usage**: Cmdlets use the `Verb-Noun` syntax. Examples include:

  - `Get-Process` retrieves information about processes running on your system.
  - `Get-Content` reads the content of a file.

  ```powershell
  PS > Get-Process -Name lsass
  ```

  This command retrieves details about the `lsass` process.

- **String Manipulation**: You can perform operations on strings directly in PowerShell.

  ```powershell
  PS > "Hello World".Length
  11
  ```

  This command outputs the length of the string "Hello World".

- **Process Management**: You can manage processes directly through PowerShell.

  ```powershell
  $process = Get-Process notepad
  $process.Kill()
  ```

  This script retrieves the `notepad` process and terminates it.

#### Pipelines

PowerShell allows chaining commands using pipelines (`|`). The output of one command can be passed as input to another.

- **Example**: Move all items from one directory to another.

  ```powershell
  Get-Item d:\t\* | Move-Item -Destination d:\t2
  ```

- **Advanced Pipeline Usage**: Chain multiple commands to filter, sort, and format data.

  ```powershell
  Get-Process |
  Where-Object { $_.Handles -ge 500 } |
  Sort-Object Handles |
  Format-Table Handles,Name,Description -Auto
  ```

  This command retrieves processes with 500 or more handles, sorts them by the number of handles, and formats the output in a table.

#### WhatIf Clause

The `-WhatIf` parameter allows you to preview the effect of a command without actually executing it.

- **Example**: Preview the deletion of processes.

  ```powershell
  gps [b-t]*[c-r] | Stop-Process -WhatIf
  ```

  Example output:

  ```
  What if: Performing the operation "Stop-Process" on target "chrome (1234)".
  What if: Performing the operation "Stop-Process" on target "cmd (5678)".
  ```

  This command shows what would happen if the processes matching the specified pattern were stopped.

#### Common Discovery Commands

- **Get-Command**: Lists all available cmdlets and functions that match a specified pattern.

  ```powershell
  PS > Get-Command *process*
  ```

- **Get-Help**: Provides help information about cmdlets.

  ```powershell
  PS > Get-Help Get-Process
  ```

- **Get-Member**: Shows the properties and methods of an object.

  ```powershell
  PS > "Hello World" | Get-Member
  ```

  Example output:

  ```
  TypeName: System.String
  Name             MemberType            Definition
  ----             ----------            ----------
  Clone            Method                System.Object Clone()
  CompareTo        Method                int CompareTo(System.Object value), int CompareTo(string strB)
  Contains         Method                bool Contains(string value)
  ...
  ```

#### Variables and .NET Interaction

You can store data in variables and interact with .NET objects.

- **Example**: Calculate the total number of handles for all processes.

  ```powershell
  PS> $handleCount = 0
  PS> foreach($process in Get-Process) { $handleCount += $process.Handles }
  PS> $handleCount
  ```

#### Cmdlet History

PowerShell keeps a history of commands you have executed.

- **Example**: Save your command history to a file.

  ```powershell
  PS> Get-History | Foreach-Object { $_.CommandLine } > c:\temp\script.ps1
  ```

#### XML Support

PowerShell can handle XML data directly.

- **Example**: Parse and work with XML content.

  ```powershell
  PS > $xmlContent = [xml] $content
  PS > $xmlContent.rss.channel.item | select Title
  ```

#### Namespace Navigation Through Providers

PowerShell can navigate through different namespaces like file systems, registry, and certificates.

- **Example**: Navigate the registry.

  ```powershell
  PS > Set-Location HKCU:\Software\Microsoft\Windows\
  PS > Get-ChildItem
  ```

#### Running Programs, Scripts, and Existing Tools

PowerShell can execute external programs and scripts.

- **Example**: Run Internet Explorer.

  ```powershell
  PS > 'C:\Program Files\Internet Explorer\iexplore.exe'
  ```

#### Specifying Command Arguments

You can pass arguments to commands.

- **Example**: Set a file attribute.

  ```powershell
  PS > attrib +R C:\Users\aseno\Documents\sunu1.pptx
  ```

#### Special Characters

PowerShell uses various special characters for different purposes:

- `"`: Quoted text
- `#`: Comment
- `$`: Variable
- `&`: Future use
- `()`: Subexpressions
- `;`: Statement separator
- `{}`: Script block
- `|`: Pipeline separator
- `` ` ``: Escape character

#### Long-Running or Background Commands

You can run commands in the background and retrieve their results later.

- **Example**: Start a background job to list documents.

  ```powershell
  PS> Start-Job -Name ListDocuments {ls -l c:\windows\Fonts}
  PS> Receive-Job ListDocuments
  ```

#### Getting Help

PowerShell has built-in help that you can update and query for detailed information about cmdlets.

- **Example**: Get detailed help for a cmdlet.

  ```powershell
  PS > Get-Help CommandName -Detailed
  ```

By understanding these basics and exploring more advanced features, you can leverage PowerShell's full potential for automating tasks and managing your systems efficiently.
