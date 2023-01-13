using _931920.tikhomirov.ilya.lab12.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.SignalR;
using Microsoft.Extensions.Options;
using System;

namespace MvcApp.Controllers
{
    public class CalcController : Controller
    {
        public IActionResult Manual()
        {
            if (Request.Method == "POST")
            {
                CalcData data = new();
                data.xnum = float.Parse(Request.Form["xnum"]);
                data.ynum = float.Parse(Request.Form["ynum"]);
                data.oper = Request.Form["oper"];
                float res = data.getRes();

                if (data.divByZero)
                    return View("Div_error");
                else
                {
                    ViewBag.Result = data.xnum.ToString() + ' ' + data.oper + ' ' + data.ynum.ToString() + " = " + res.ToString();
                    return View("Result");
                }
            }
            else
                return View();
        }

        [HttpGet]
        public IActionResult ManualWithSeparateHandlers()
        {
            return View();
        }

        [HttpPost]
        public IActionResult ManualWithSeparateHandlers(string s)
        {
            CalcData data = new();
            data.xnum = float.Parse(Request.Form["xnum"]);
            data.ynum = float.Parse(Request.Form["ynum"]);
            data.oper = Request.Form["oper"];

            float res = data.getRes();

            if (data.divByZero)
                return View("Div_error");
            else
            {
                ViewBag.Result = data.xnum.ToString() + ' ' + data.oper + ' ' + data.ynum.ToString() + " = " + res.ToString(); ;
                return View("Result");
            }

        }

        [HttpGet]
        public IActionResult ModelBindingInParameters()
        {
            return View();
        }

        [HttpPost]
        public IActionResult ModelBindingInParameters(float xnum, float ynum, string oper)
        {
            CalcData data = new();
            data.xnum = xnum;
            data.ynum = ynum;
            data.oper = oper;

           data.getResModel();

            if (data.divByZero)
                return View("Div_error");
            else 
            {
                ViewBag.Result = data.resString();
                return View("Result");
            }
            
        }


        [HttpGet]
        public IActionResult ModelBindingInSeparateModel()
        {
            return View();
        }

        [HttpPost]
        public IActionResult ModelBindingInSeparateModel(CalcData data)
        {
            data.getResModel();

            if (data.divByZero)
                return View("Div_error");
            else
            {
                ViewBag.Result = data.resString();
                return View("Result");
            }
            
        }
    }
} 