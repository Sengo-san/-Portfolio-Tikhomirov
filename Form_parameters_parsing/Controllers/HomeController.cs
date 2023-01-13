using Microsoft.AspNetCore.Mvc;

namespace _931920.tikhomirov.ilya.lab12.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
