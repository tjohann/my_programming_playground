//
// Demo for handling User-Infos within Go
//
// see also https://pkg.go.dev/os/user
//

package main

import (
	"fmt"
	"log"
	"os/user"
)


func main() {

	user, err := user.Current()
	if err != nil {
		log.Fatalf(err.Error())
	}

	fmt.Println("Hello World written in Go!\n")

	fmt.Printf("User: %s\n", user.Username) // login user name
	fmt.Printf("User-ID: %s\n", user.Uid)
	fmt.Printf("Group-ID: %s\n", user.Gid)
	fmt.Printf("Name: %s\n", user.Name)     // the long name of passwd
	fmt.Printf("Home directory: %s \n", user.HomeDir)
}
