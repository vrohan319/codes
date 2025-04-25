package com.eazybyte.springsecuritysection.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class WelcomeController {

    @GetMapping("/welcome")
    public String sayWelcome(){
        return "welcome to spring app with security";
    }


}
